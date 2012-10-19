
# The root versions to compare
#ROOTVERSIONS="root-roostats-git root-roostats-branch root-5.34.01-tag" # root-5.32.00-patches root-trunk
ROOTVERSIONS="root-roostats-git root-5.34.01-tag" # root-5.32.00-patches root-trunk

# The Tests to run
#XMLFILES="example example_Expression example_params example_Ultimate example_ShapeSys example_ShapeSys2D examples/example_DataDriven"
#XMLFILES="example example_params example_Ultimate example_ShapeSys example_ShapeSys2D examples/example_DataDriven"
XMLFILES="example"
#PYTHONSCRIPTS="example"
#CPPSCRIPTS="example"
CPPSCRIPTS="asimov"

#
# The rest is done automatically
#

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

# Create the commands used to run the tests
RUNCOMMANDS=()
for xml in $XMLFILES
do
    RUNCOMMANDS+=("hist2workspace config/${xml}.xml")
done
for script in $PYTHONSCRIPTS
do
    RUNCOMMANDS+=("python scripts/${script}.py -b")
done
for script in $CPPSCRIPTS
do
    RUNCOMMANDS+=("root.exe -q -b scripts/${script}.C++")
done

# Create the logs
mkdir -p logs
for build in $ROOTVERSIONS
do
    #for version in $TESTS
    for ((i = 0; i < ${#TESTS[@]}; i++))
    do

	TESTNAME=`basename ${TESTS[$i]}`
	echo "Running Test: ${TESTNAME} with ROOT version ${build}"
	source /usr/local/root_versions/${build}/bin/thisroot.sh

	# Run the command (and time it)
	LOGNAME=logs/${build}_${TESTNAME}.log


	BEGIN=`perl -MTime::HiRes -e 'print int(1000 * Time::HiRes::gettimeofday),"\n"'`
	${RUNCOMMANDS[$i]}  2>&1 | tee $LOGNAME 
	END=`perl -MTime::HiRes -e 'print int(1000 * Time::HiRes::gettimeofday),"\n"'`
	DIFF=`expr $END - $BEGIN`

	# Now, get the reduced version of the log
	# We are only interested in the fit output
	sed -n '/**MIGRAD/,/**MINOS:/p' logs/${build}_${TESTNAME}.log >logs/${build}_${TESTNAME}_reduced.log

	echo "Time: $DIFF (ms)"
	echo "Time: $DIFF (ms)" >>$LOGNAME

    done
done


# Create a summary file for the tests
SUMMARY=Summary.log
DIFFDIRECTORY='diffs'
mkdir -p ${DIFFDIRECTORY}

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

	#for version in $TESTS
	#for version in $TESTS "${TESTS[@]}"
	for version in ${TESTS[@]}
	do
	    TESTNAME=`basename ${version}`
	    logA=logs/${buildA}_${TESTNAME}_reduced.log
	    logB=logs/${buildB}_${TESTNAME}_reduced.log
	    DIFF=$(diff -b -B $logA $logB)
	    if [ "$DIFF" = "" ]
	    then
		echo "Passed Test for ${TESTNAME}: $buildA $buildB"
		echo "Passed Test for ${TESTNAME}: $buildA $buildB" >>${SUMMARY}
	    else
		echo "Failed Test for ${TESTNAME}: $buildA $buildB"
		echo "Failed Test for ${TESTNAME}: $buildA $buildB" >>${SUMMARY}
		echo -e "\n DIFF:" >>${SUMMARY}
		echo "${DIFF}" >>${SUMMARY}
		echo -e "\n" >>${SUMMARY}
		# And log to the diff file
		echo "${DIFF}" >${DIFFDIRECTORY}/diff_${buildA}_${buildB}_${TESTNAME}.log
	    fi
	done
    done
done
