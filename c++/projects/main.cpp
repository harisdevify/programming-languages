#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string parseInline(string line) {
    // string.find(searchText, startPosition);
    // string.substr(from, length)
    size_t first;
    while ((first = line.find("**")) != string::npos){
      size_t second = line.find("**", first + 2);
      if(second != string::npos){
        string before = line.substr(0, first);
        size_t start = (first + 2);
        string boldText = line.substr(first+2, second - start);
        string after = line.substr(second + 2);
        line=before + "<strong>" + boldText + "</strong>" + after;
      }else{
        break;
      }
    }
    return line;
}

int main(){
  char filename[]="test.md";
  ifstream file(filename);
  ofstream outputfile("index.html");
  if(!file){
    cerr<<"I think file path is wrong!"<<endl;
    exit(1);
  }

  string line;
  while(getline(file, line)){
    int hashcount =0;
    while(hashcount < line.length() && line[hashcount] == '#'){
      hashcount++;
    }
    if(hashcount > 0 && hashcount < line.length() && line[hashcount] == ' '){
      outputfile << "<h" << hashcount << ">" << line.substr(hashcount + 1) << "</h" << hashcount << ">" << endl;
    }else {
      if(!line.empty()){
        string parsed =parseInline(line);
        outputfile << "<p>" << parsed << "</p>" << endl;
      } else {
        cout << endl;
      }
    }
  }

  outputfile.close();
  return 0;
}
