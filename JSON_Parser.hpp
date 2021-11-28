/**
* @file JSON_Read.hpp
* @author Francisco Dos Reis
* @version 0.0
* @date 28.11.2021
* @brief class JSONRead declaration
* @brief allow reading datas JSON files into Eigen library matrix
*/
#pragma once
#include <stdio.h>

#include <iostream>
#include <string>
#include <Eigen/Dense>

#include <fstream>
#include <iomanip>
#include <locale>

#include <string>
#include <math.h>
#include <malloc.h>

using namespace Eigen;

/**
 * @brief class for reading datas from json to Eigen
*/
class JSONRead {
private:
	struct json_object* parsed_json;
	void* Buffer;
public:
	/**
	* @brief Init of the JSON parser and input file
	* @param name of the JSON file
	*/
	JSONRead(const char * file);
	~JSONRead();

	/**
	 * @brief read a double value
	 * @param name name of the value in JSON file
	 * @return double value returned
	*/
	double ReadDouble(const char* name);

	/**
	 * @brief read a float value
	 * @param name name of the value in JSON file
	 * @return float value returned
	*/
	float ReadFloat(const char* name);

	/**
	 * @brief read an int value from JSON file
	 * @param name name of the value in JSON file
	 * @return int value returned
	*/
	int ReadInt(const char* name);

	/**
	 * @brief read an EIgen float array 
	 * @param T Eigen float dynamic array
	 * @param name name of the array in JSON file
	*/
	void ReadFloatArray(ArrayXf& T, const char* name);

	/**
	 * @brief read an EIgen float array
	 * @param T Eigen float dynamic Matrix
	 * @param name name of the array in JSON file
	*/
	void ReadFloatMatrix(MatrixXf& T, const char* name);

	/**
	 * @brief read an EIgen float array
	 * @param T Eigen float dynamic Vector
	 * @param name name of the array in JSON file
	*/
	void ReadFloatVector(VectorXf& T, const char* name);

	/**
	 * @brief read an EIgen int array
	 * @param T Eigen int dynamic array
	 * @param name name of the array in JSON file
	*/
	void ReadIntVector(VectorXi& T, const char* name);

	/**
	 * @brief read a array of string 
	 * @param name name of the array in JSON file
	 * @return array of char **
	*/
	char** ReadStringArray(const char* name);

	/**
	 * @brief read a string value from JSON file
	 * @param output char ** of the string content
	 * @param name name of the value in JSON file
	*/
	void ReadString(const char* output, const char* name);

};
