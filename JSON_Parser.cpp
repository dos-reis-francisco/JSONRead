/**
* @file input_data.c
* @author Francisco Dos Reis
* @version 0.0
* @date 22.04.2021
* @brief fichier permettant d'entrer des matrices de données Eigen 
* @brief à partir d'un fichier JSON
* @brief utilise la librairie JSON-C
*/

#include <stdio.h>
#include "./json-c/json.h"
#include "JSON_Parser.hpp"
#include "string.h"
#include "malloc.h"

/**
 * @brief Init of the JSON parser and input file
 * @param name of the JSON file 
*/
JSONRead::JSONRead(const char *name) {
	FILE* fp;
	Buffer = _aligned_malloc(10000, 64);
	if (Buffer == NULL) return;

	int err=fopen_s(&fp, name, "r");
	if (err != 0) return ;

	fread(Buffer, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse((const char* )Buffer);
}

JSONRead::~JSONRead()
{
	_aligned_free(Buffer);
}

/**
 * @brief read a double value
 * @param name name of the value in JSON file
 * @return double value returned
*/
double JSONRead::ReadDouble(const char * name) {
	struct json_object* data;
	double R;
	int ret;

	ret=json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return 0;
	R = json_object_get_double(data);
	return R;

}

/**
 * @brief read a double value
 * @param name name of the value in JSON file
 * @return double value returned
*/
float JSONRead::ReadFloat(const char* name) {
	struct json_object* data;
	float R;
	int ret;

	ret = json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return 0;
	R = (float) json_object_get_double(data);
	return R;

}

/**
 * @brief read an int value from JSON file
 * @param name name of the value in JSON file
 * @return int value returned
*/
int JSONRead::ReadInt(const char* name) {
	struct json_object* data;
	int R;
	int ret;

	ret=json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return 0;

	R = json_object_get_int(data);
	return R;
}

/**
 * @brief read a string value from JSON file
 * @param output char ** of the string content, must be a char output[256]
 * @param name name of the value in JSON file
*/
void JSONRead::ReadString(const char* output, const char* name) {
	struct json_object* data;
	char* T;
	int ret;

	ret=json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) { output = NULL; return; }
	T =(char *) json_object_get_string(data);
	memcpy_s((void*)output, 256, T, strnlen_s(T,256)+1);
}

/**
 * @brief read a array of double into a MFDR matrix length x 1
 * @param T void MFDR matrix
 * @param name name of the array in JSON file
*/
void JSONRead::ReadFloatArray(ArrayXf& T, const char* name) {
	struct json_object* data;
	struct json_object* element;
	size_t i, nindex;
	int ret;

	ret=json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return ;

	nindex = json_object_array_length(data);
	T.resize(nindex);

	for (i = 0; i < nindex; i++) {
		element = json_object_array_get_idx(data, i);
		T(i) =(float) json_object_get_double(element);
	}
}


/**
 * @brief read a array of double into a MFDR matrix length x 1
 * @param T void MFDR matrix
 * @param name name of the array in JSON file
*/
void JSONRead::ReadFloatMatrix(MatrixXf& T, const char* name) {
	struct json_object* data;
	struct json_object* element;
	size_t i, nindex;
	int ret;

	ret = json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return;

	nindex = json_object_array_length(data);
	T.resize(nindex,1);

	for (i = 0; i < nindex; i++) {
		element = json_object_array_get_idx(data, i);
		T(i,0) = (float)json_object_get_double(element);
	}
}
/**
 * @brief read a array of double into a MFDR matrix length x 1
 * @param T void MFDR matrix
 * @param name name of the array in JSON file
*/
void JSONRead::ReadFloatVector(VectorXf& T, const char* name) {
	struct json_object* data;
	struct json_object* element;
	size_t i, nindex;
	int ret;

	ret = json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return;

	nindex = json_object_array_length(data);
	T.resize(nindex);

	for (i = 0; i < nindex; i++) {
		element = json_object_array_get_idx(data, i);
		T(i) = (float)json_object_get_double(element);
	}
}

void JSONRead::ReadIntVector(VectorXi& T, const char* name) {
	struct json_object* data;
	struct json_object* element;
	size_t i, nindex;
	int ret;

	ret = json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return;

	nindex = json_object_array_length(data);
	T.resize(nindex);

	for (i = 0; i < nindex; i++) {
		element = json_object_array_get_idx(data, i);
		T(i) = json_object_get_int(element);
	}
}

/**
 * @brief read a array of string into a matrix length x 1
 * @param T void MFDR matrix
 * @param name name of the array in JSON file
*/
char ** JSONRead::ReadStringArray(const char* name) {
	struct json_object* data;
	struct json_object* element;
	size_t i, nindex, lenString;
	char *buffer;
	char** T;
	int ret;

	ret=json_object_object_get_ex(parsed_json, name, &data);
	if (ret == 0) return NULL;

	nindex = json_object_array_length(data);
	
	T =(char**) _aligned_malloc(nindex * sizeof(data),64);

	if (T == NULL) return NULL;

	for (i = 0; i < nindex; i++) {
		element = json_object_array_get_idx(data, i);
		lenString=(size_t) json_object_get_string_len(element)+1;
		T[i] =(char*) _aligned_malloc((lenString+1) * sizeof(char),64);
		buffer =(char*) json_object_get_string(element);
		if (T[i]!=NULL) memcpy(T[i], buffer, lenString+1);
	}
	return T;
}
