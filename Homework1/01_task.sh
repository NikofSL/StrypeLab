#!/bin/bash

# Function to ask if the user wants to proceed with the step
ask_proceed() {
    read -p "$1 (y/n)? " response
    if [[ "$response" != "y" ]]; then
        echo "Step skipped."
        return 1
    fi
    return 0
}

# Function to check if the directory has write access and exit on failure
check_write_access() {
    local path="$1"
    if [ ! -w "$path" ]; then
        echo "Error: You don't have write access to $path." 1>&2
        exit 1
    fi
}

# Step 1: Create day1 directory and empty files
ask_proceed "Create directory 'day1' and empty files 'test1', 'test2', 'test3'" && {
    check_write_access "." # Check write access for current directory
    mkdir -p day1
    touch day1/test1 day1/test2 day1/test3
    echo "Step 1 completed."
}

# Step 2: Write content to files
ask_proceed "Add content to 'test1', 'test2', 'test3'" && {
    check_write_access "day1"
    echo "Hello Bash" > day1/test1
    date > day1/test2
    (cd day1 && pwd) > day1/test3
    echo "Step 2 completed."
}

# Step 3: Create testDir and copy test files
ask_proceed "Create 'testDir' in 'day1' and copy 'test1', 'test2', 'test3' to it" && {
    check_write_access "day1"
    mkdir -p day1/testDir
    cp day1/test1 day1/test2 day1/test3 day1/testDir/
    echo "Step 3 completed."
}

# Step 4: Create testNested in testDir and copy test1, test2
ask_proceed "Create 'testNested' in 'testDir' and copy 'test1', 'test2' to it" && {
    check_write_access "day1/testDir"
    mkdir -p day1/testDir/testNested
    cp day1/testDir/test1 day1/testDir/test2 day1/testDir/testNested/
    echo "Step 4 completed."
}

# Step 5: Delete test1, test2, test3 from day1
ask_proceed "Delete 'test1', 'test2', 'test3' from 'day1'" && {
    check_write_access "day1"
    rm -f day1/test1 day1/test2 day1/test3
    echo "Step 5 completed."
}

# Step 6: Copy testDir content to testDirCopy
ask_proceed "Copy content of 'testDir' to 'testDirCopy'" && {
    check_write_access "day1"
    cp -r day1/testDir/ day1/testDirCopy
    echo "Step 6 completed."
}

# Step 7: Delete test1 from testDir
ask_proceed "Delete 'test1' from 'testDir'" && {
    check_write_access "day1/testDir"
    rm -f day1/testDir/test1
    echo "Step 7 completed."
}

# Step 8: Delete all content in testDirCopy
ask_proceed "Delete all content in 'testDirCopy'" && {
    check_write_access "day1/testDirCopy"
    rm -rf day1/testDirCopy/*
    echo "Step 8 completed."
}

echo "Script execution completed."
