/*
Flood Fill - [Leetcode - 733(Easy)]
====================================
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
*/ 

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int currRow, int currCol, int initialColor, int newColor){
    
    int n = image.size(); // total rows
    int m = image[0].size(); // total columns
    
    // Check if the current cell is within the grid and has the initial color 
    if(currRow < 0 or currCol < 0 or currRow >= n or currCol >= m) return; // You are outside of grid

    // If the cell you landed is not of inital color
    if(image[currRow][currCol] != initialColor) return;

    image[currRow][currCol] = newColor;
    dfs(image, currRow + 1, currCol, initialColor, newColor); // down
    dfs(image, currRow, currCol - 1, initialColor, newColor); // left
    dfs(image, currRow - 1, currCol, initialColor, newColor); // up
    dfs(image, currRow, currCol + 1, initialColor, newColor); // right
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){ // sr -> source row ; sc -> source column
    if(color == image[sr][sc]) return image;
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}

int main(){

    int rows, cols, sr, sc, color;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;

    // 2D vector to store the image
    vector<vector<int>>image(rows, vector<int>(cols));

    // Ask user for the image data
    cout<<"Enter the image data:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin>>image[i][j];
        }
    }

    // Ask user for the source row, source column, and color
    cout<<"Enter the source row: ";
    cin>>sr;
    cout<<"Enter the source column: ";
    cin>>sc;
    cout<<"Enter the color: ";
    cin>>color;

    // Print the original image
    cout<<"Original Image:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout<<image[i][j]<< " ";
        }
        cout<<endl;
    }

    // Perform flood fill
    vector<vector<int>> result = floodFill(image, sr, sc, color);

    // Print the result
    cout<<"Result after flood fill:"<<endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}