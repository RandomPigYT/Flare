#!/bin/bash


createdDirs=""

for i in "$@"
do
	
	if [[ -z "$(find obj -mindepth 1 -type d -wholename "$i")" ]]; then
		mkdir $i
		echo "Created directory $i"

		createdDirs="true"
	fi

done

if [[ "$createdDirs" ]]; then

	printf "\n"
fi


