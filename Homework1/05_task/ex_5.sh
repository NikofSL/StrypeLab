# Check for valid numbers
awk '{if ($1 !~ /^-?[0-9]+(\.[0-9]+)?$/) { print "Invalid entry: " $1; exit 1; }}' numbers.txt

# If validation is successful, find the smallest and largest numbers
if [ $? -eq 0 ]; then
    echo "The smallest number is: $(sort -n numbers.txt | head -1)"
    echo "The largest number is: $(sort -n numbers.txt | tail -1)"
else
    echo "The file contains invalid data."
fi
