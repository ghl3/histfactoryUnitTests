

#ROOTVERSIONS="root-histfactory-dev root-roostats-dev root-roostats-branch root-5.32.00-patches root-trunk"
ROOTVERSIONS="root-roostats-git root-roostats-branch root-trunk"

XMLFILES="example example_Expression example_params example_Ultimate example_ShapeSys example_ShapeSys2D"
PYTHONSCRIPTS="example"
CPPSCRIPTS="example"

# Make a list of titles for the various tests
TESTS=()
for xml in $XMLFILES
do
    TESTS+=("$xml")
done
for script in $PYTHONSCRIPTS
do
    TESTS+=("${script}_py")
done
for script in $CPPSCRIPTS
do
    TESTS+=("${script}_C")
done

#$XMLFILES $PYTHONSCRIPTS $CPPSCRIPTS)
#TESTS=($XMLFILES $PYTHONSCRIPTS $CPPSCRIPTS)

# Create the commands used to run the tests
RUNCOMMANDS=()
for xml in $XMLFILES
do
    RUNCOMMANDS+=("hist2workspace $xml")
done
for script in $PYTHONSCRIPTS
do
    RUNCOMMANDS+=("python scripts/$script.py")
done
for script in $CPPSCRIPTS
do
    RUNCOMMANDS+=("root -b scripts/$script.C++")
done

#for xml in $XMLFILES
#do
#    RUNCOMMANDS+=("bob $xml")
#done

for i in "${RUNCOMMANDS[@]}"
do
    echo $i
done

for ((i = 0; i < ${#TESTS[@]}; i++)); do
  echo "${TESTS[$i]} ${RUNCOMMANDS[$i]}"
done



exit

RUNCOMMANDS=""
for xml in $XMLFILES
do
    RUNCOMMANDS="$RUNCOMMANDS hist2workspace $xml;"
done
for script in $PYTHONSCRIPTS
do
    RUNCOMMANDS="$RUNCOMMANDS python scripts/$script; "
done
for script in $CPPSCRIPTS
do
    RUNCOMMANDS="$RUNCOMMANDS root -b scripts/$script++; "
done

IFS=';' read -ra ADDR <<< "$RUNCOMMANDS"
for i in "${ADDR[@]}"; do
    echo $i
done


exit




exit

# Create the logs
for build in $ROOTVERSIONS
do
    for version in $TESTS
    do
	source /usr/local/root_versions/${build}/bin/thisroot.sh
	#/usr/local/root_versions/${build}/bin/hist2workspace config/${version}.xml 2>&1 | tee logs/${build}_${version}.log 
	hist2workspace config/${version}.xml 2>&1 | tee logs/${build}_${version}.log 
	# Now, get the reduced version of the log
	sed -n '/**MIGRAD/,/**MINOS:/p' logs/${build}_${version}.log >logs/${build}_${version}_reduced.log
    done
done

# Create a summary file for the tests
SUMMARY=tests/Summary.txt
echo "Summary:" >${SUMMARY}

# Now, do the tests
for buildA in $ROOTVERSIONS
do
    for buildB in $ROOTVERSIONS
    do

	if [ $buildA = $buildB ]
	then
	    continue
	fi

	for version in $TESTS
	do
	    logA=logs/${buildA}_${version}_reduced.log
	    logB=logs/${buildB}_${version}_reduced.log
	    DIFF=$(diff -b -B $logA $logB)
	    if [ "$DIFF" = "" ]
	    then
		echo "Passed Test for ${version}: $buildA $buildB"
		echo "Passed Test for ${version}: $buildA $buildB" >>${SUMMARY}
	    else
		echo "Failed Test for ${version}: $buildA $buildB"
		echo "Failed Test for ${version}: $buildA $buildB" >>${SUMMARY}
		echo "${DIFF}" >tests/diff_${buildA}_${buildB}_${version}.log
	    fi
	done
    done
done





