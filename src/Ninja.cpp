#include <Zoro/Ninja.h>
#include <fstream>

#include <iostream>

// outputs temp files to like src/ because its in the og filepath
//
void WriteToNinja(const Project& proj)
{
  // defines and includes not singular
  std::ofstream output;
  output.open("build.ninja");
  output << "rule cc" << std::endl;
  output << "   command = g++ -m64 -MMD -MP -m64 -std=c++" << proj.cppversion << " $cflags -c $in -o $out ";
  for (const std::string& includePath : proj.include)
    output << "-I" << includePath << " ";
  for (const std::string& defineStmt : proj.define)
    output << "-D" << defineStmt << " ";
  output << std::endl;

  output << "rule link\n   command = g++ -o $out $in   -L/usr/lib64 -m64 -s\n\n";

  output << "rule ar\n   command = ar rcs $out $in\n   description = ar $out\n\n";
 
  for (const std::string& filePath : proj.files)
  {
    size_t extStart = filePath.find(".");
    output << "build " << proj.outputdir << "/" << filePath.substr(0, extStart) << ".o: ";
    output << "cc " << filePath << std::endl; 
  }
  output << std::endl;

  std::string cmd = proj.type == "exec" ? "link" : "ar";
  std::string ftype = proj.type == "exec" ? ".exe" : ".a";
  output << "build " << proj.outputdir <<"/" << proj.name << ftype <<": " << cmd <<" ";
  for (const std::string& filePath : proj.files)
  {
    size_t extStart = filePath.find(".");
    output << proj.outputdir << "/" << filePath.substr(0, extStart) << ".o ";
  }
  output << std::endl;
  output.close();
}
