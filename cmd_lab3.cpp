#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int result=0;
  map <string, bool> used_keys;

  int index = -1;
  const char* short_options = "hlvdrcRCV::?";  
  //h-help, v-version, list, d-download, r-run, c-cat, V-Value
  
  const struct option long_options[] = {
  
        {"help",0,NULL,'h'},
        {"version",0,NULL,'v'},
        {"list",0,NULL,'l'},
    	{"download", 0, NULL, 'd'},
    	{"run", 0, NULL, 'r'},
    	{"cat", 0, NULL, 'c'},
    	{"Rock", 0, NULL, 'R'},
    	{"Cut", 0, NULL, 'C'},
    	{"Value", 25, NULL, 'V'},
    };

 
  while ((result = getopt_long(argc,argv,short_options,long_options, &index)) != -1){
    switch (result){
    case 'h': {
      if (used_keys["h"] == false) {
        printf("Arg: Help\n"); 
        used_keys["h"] = true;
        break;
      } 
      break;
    }
    case 'R': {
      if (used_keys["R"] == false) {
        printf("Arg: Rock Rock\n"); 
        used_keys["R"] = true;
        break;
      } 
      break;
    }
    case 'l': {
      if (used_keys["l"] == false) {
        printf("Arg: List\n"); 
        used_keys["l"] = true;
        break;
      }
      break;
    }
    case 'v': {
      if (used_keys["v"] == false) {
        printf("Arg: Version\n"); 
        used_keys["v"] = true;
        break;
      }
      break;
    }
    case 'r': {
      if (used_keys["r"] == false) {
        printf("Arg: run forest run\n"); 
        used_keys["r"] = true;
        break;
      }
      break;
    }
    case 'c': {
      if (used_keys["c"] == false) {
        printf("Arg: cat is a good boi\n"); 
        used_keys["c"] = true;
        break;
      }
      break;
    }
    case 'C': {
      if (used_keys["C"] == false) {
          printf("Arg: Cut it\n"); 
          used_keys["V"] = true;
          break;
      }
      break;
    }
    case 'd': {
      if (used_keys["d"] == false) {
          printf("Arg: DOWNLOAD\n"); 
          used_keys["d"] = true;
          break;
      }
      break;
    }
    case 'V': {
      if (used_keys["V"] == false) {
      	if (optarg == NULL){
      		printf("Arg: Value NULL\n");
      		used_keys["V"] = true;
      	}else{
      		printf("Arg: Value is %s\n", optarg); 
          	used_keys["V"] = true;
          }
          
          break;
      }
      break;
    }
    
    default: {
      printf("Key not found\n");
      break;
      }
        };
    index = -1;
  };
};
