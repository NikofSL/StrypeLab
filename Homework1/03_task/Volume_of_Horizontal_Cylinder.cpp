
#include <iostream>
#include <cmath> // for M_PI and trigonometry functions

// Function to calculate the segment area of a circle given radius and water height
double calculate_segment_area(double radius, double water_height) {
	if (water_height >= radius * 2) {
		// If water height is greater than or equal to the diameter, it is fully filled
		return M_PI * radius * radius;
	}
	else if (water_height <= 0) {
		// If water height is zero or negative, there's no water
		return 0.0;
	}
	else {
		double theta = 2 * acos(1 - water_height / radius);
		return 0.5 * radius * radius * (theta - sin(theta));
	}
}

// Function to calculate the volume of water in a horizontal cylinder
double calculate_horizontal_cylinder_volume(double radius, double length, double water_height) {
	double segment_area = calculate_segment_area(radius, water_height);
	return length * segment_area;
}

int main() {
	double radius, length, water_height;

	std::cout << "Enter the barrel's radius (in meters): ";
	std::cin >> radius;

	std::cout << "Enter the barrel's length (in meters): ";
	std::cin >> length;

	std::cout << "Enter the height of the water (in meters): ";
	std::cin >> water_height;

	double volume = calculate_horizontal_cylinder_volume(radius, length, water_height);

	std::cout << "The volume of water in the horizontal barrel is: " << volume << " cubic meters." << std::endl;

	return 0;
}
