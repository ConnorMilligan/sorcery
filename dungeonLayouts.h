//Hardcoded testing dungeons
#ifndef GRAPHICS_DUNGEONLAYOUTS_H
#define GRAPHICS_DUNGEONLAYOUTS_H

#include <vector>
#include "Quad.h"


//I promise this is an acceptable way of doing this :)
std::vector<std::vector<bool>> fungeon{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                                       {1, 0, 0, 0, 0, 1, 1, 1, 1, 1}, 
                                       {1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, 
                                       {1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, 
                                       {1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, 
                                       {1, 0, 1, 1, 0, 1, 0, 0, 0, 1}, 
                                       {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                                       {1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

std::vector<std::vector<bool>> fungeon2{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                                       {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                                       {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
                                       {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                                       {1, 0, 1, 1, 0, 1, 0, 0, 0, 1},
                                       {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                                       {1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

std::vector<std::vector<bool>> fungeon3{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                                        {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                        {1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                                        {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                                        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
                                        {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
                                        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
                                        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


std::vector<std::vector<bool>> fungeon4{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};



// Oh boy
// Each entry contains a vector with the start and end point of each maze
std::vector<std::vector<point>> startPoints = {
        {{1,8},{8,6}}, //Dungeon 1
        {{1,1},{8,1}}
};

// Oh dear
// Each entry contains a 2d array of booleans
std::vector<std::vector<std::vector<bool>>> dungeons = {fungeon, fungeon4};

//
//// Oh boy
//// Each entry contains a vector with the start and end point of each maze
//std::vector<std::vector<point>> startPoints = {
//        {{1,8},{8,6}}, //Dungeon 1
//        {{1,8},{8,6}}, // Dungeon 2
//        {{1,1},{8,1}}, // Dungeon 3
//        {{1,1},{8,1}}
//};
//
//// Oh dear
//// Each entry contains a 2d array of booleans
//std::vector<std::vector<std::vector<bool>>> dungeons = {fungeon, fungeon2, fungeon3, fungeon4};


#endif