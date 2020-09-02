/* 733. Flood Fill

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image. */

class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int r, int c, int prevC, int newC)
    {
        if (r < 0 or r >=image.size() or c < 0 or c >= image[0].size())
        {
            return;
        }
        if (image[r][c] != prevC)
            return;
        if (image[r][c] == newC)
            return;
        image[r][c] = newC;
        floodFillUtil(image, r+1, c, prevC, newC);
        floodFillUtil(image, r-1, c, prevC, newC);
        floodFillUtil(image, r, c+1, prevC, newC);
        floodFillUtil(image, r, c-1, prevC, newC);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevC = image[sr][sc]; 
        floodFillUtil(image, sr, sc, prevC, newColor); 
        return image;
    }
};