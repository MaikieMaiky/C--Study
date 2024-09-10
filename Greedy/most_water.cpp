// container with most water
// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// thought:
// the length of the container is determined by the shorter board
// we can use 2 pointers to iterate the array, and calculate the area of the container
// let's analyze(important): if move a pointer, the width of the container'll minus 1, so we need to find a higher board to make up for the loss
// 1. move the higher board, the width minus, the height does not change or be shorter, so the area will be smaller
// 2. move the shorter board, the width minus, the height may increase, so the area may be larger
// so we should move the shorter board to find a larger area

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int l = 0;
    int r = height.size() - 1;
    int maxArea = 0;

    while (l < r)
    {
        // calculate the current area
        int area = min(height[l], height[r]) * (r - l);
        // print the current area's size
        cout << "area: " << area << endl;
        // update the max area
        maxArea = max(maxArea, area);
        // move the shorter board
        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return maxArea;
}


// let's hace a test
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // the expected output is 49
    cout << maxArea(height) << endl;
    return 0;
}

// make most_water