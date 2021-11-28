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

#define EIGEN_USE_MKL_ALL

class JSONRead {
private:
	struct json_object* parsed_json;
	void* Buffer;
public:
	JSONRead(const char * file);
	~JSONRead();

	/**
	 * @brief read a double value
	 * @param name name of the value in JSON file
	 * @return double value returned
	*/
	double ReadDouble(const char* name);

	float ReadFloat(const char* name);

	/**
	 * @brief read an int value from JSON file
	 * @param name name of the value in JSON file
	 * @return int value returned
	*/
	int ReadInt(const char* name);

	/**
	 * @brief read a array of double into a MFDR matrix length x 1
	 * @param T void MFDR matrix
	 * @param name name of the array in JSON file
	*/
	void ReadFloatArray(ArrayXf& T, const char* name);

	void ReadFloatMatrix(MatrixXf& T, const char* name);

	void ReadFloatVector(VectorXf& T, const char* name);

	void ReadIntVector(VectorXi& T, const char* name);

	/**
	 * @brief read a array of string into a MFDR matrix length x 1
	 * @param T void MFDR matrix
	 * @param name name of the array in JSON file
	*/
	
	char** ReadStringArray(int* Timages, const char* name);

	/**
	 * @brief read a string value from JSON file
	 * @param output char ** of the string content
	 * @param name name of the value in JSON file
	*/
	void ReadString(const char* output, const char* name);

};
