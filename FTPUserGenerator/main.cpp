//
//  main.cpp
//  FTPUserGenerator
//
//  Created by 許佑任 on 2015/9/10.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <string>
#include<vector>

#include "md5.h"


using namespace rapidxml;
using std::cout;
using std::endl;
using std::string;

const string FILEZILLA_SERVER_PATH = "FileZilla Server.xml";

const char * RANDOM_NUMBER_GENERATION_TABLE =
    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int PASSWORD_SIZE = 8;

const char * const ROOT_DIR = "D:\\__LABWEB__\\FTP\\USER\\CP2015\\104\\";

void createUser(std::vector<string> &, std::vector<string> &, std::vector<string> &);
void generateStudent(std::vector<string> &);
void encrptyPassword(
    std::vector<string> &,
    std::vector<string> &,
    std::vector<string> &,
    void (*result)(std::vector<string> &, std::vector<string> &, std::vector<string> &, std::vector<string> &)
);
void printlnResult(std::vector<string> &, std::vector<string> &, std::vector<string> &, std::vector<string> &);

int main(int argc, const char * argv[]) {
  std::vector<string> studentList;
  
  //第一組 20人
  studentList.push_back("B033012033");
  studentList.push_back("B033012034");
  studentList.push_back("B043012004");
  studentList.push_back("B043012005");
  studentList.push_back("B043012006");
  studentList.push_back("B043012007");
  studentList.push_back("B043012008");
  studentList.push_back("B043012029");
  studentList.push_back("B043012030");
  studentList.push_back("B043012031");
  
  studentList.push_back("B043012032");
  studentList.push_back("B043012033");
  studentList.push_back("B043012034");
  studentList.push_back("B043012035");
  studentList.push_back("B043012036");
  studentList.push_back("B043012037");
  studentList.push_back("B043012038");
  studentList.push_back("B043012039");
  studentList.push_back("B043012040");
  studentList.push_back("B043012041");
  
  // 第二組 20人
  studentList.push_back("B043012009");
  studentList.push_back("B043012010");
  studentList.push_back("B043012011");
  studentList.push_back("B043012012");
  studentList.push_back("B043012013");
  studentList.push_back("B043012014");
  studentList.push_back("B043012015");
  studentList.push_back("B043012016");
  studentList.push_back("B043012017");
  studentList.push_back("B043012018");
  
  studentList.push_back("B043012042");
  studentList.push_back("B043012043");
  studentList.push_back("B043012044");
  studentList.push_back("B043012045");
  studentList.push_back("B043012046");
  studentList.push_back("B043012047");
  studentList.push_back("B043012048");
  studentList.push_back("B043012049");
  studentList.push_back("B043012050");
  studentList.push_back("B043012051");
  
  // 第三組 20人
  studentList.push_back("B043012019");
  studentList.push_back("B043012020");
  studentList.push_back("B043012021");
  studentList.push_back("B043012022");
  studentList.push_back("B043012023");
  studentList.push_back("B043012024");
  studentList.push_back("B043012025");
  studentList.push_back("B043012026");
  studentList.push_back("B043012027");
  studentList.push_back("B043012028");
  
  studentList.push_back("B043012052");
  studentList.push_back("B043012053");
  studentList.push_back("B043012054");
  studentList.push_back("B043012055");
  studentList.push_back("B043012056");
  studentList.push_back("B043012057");
  studentList.push_back("B043012058");
  studentList.push_back("B043012059");
  studentList.push_back("B043012060");
  studentList.push_back("B043012061");
  
  // 第四組 20人
  studentList.push_back("B043012001");
  studentList.push_back("B043012002");
  studentList.push_back("B043012003");
  studentList.push_back("B023011058");
  studentList.push_back("B023012019");
  studentList.push_back("B023012033");
  studentList.push_back("B033011061");
  studentList.push_back("B035090031");
  studentList.push_back("B012040036");
  studentList.push_back("B024020049");
  
  studentList.push_back("B041010038");
  studentList.push_back("B042010023");
  studentList.push_back("B043090022");
  studentList.push_back("B022030022");
  studentList.push_back("B045090008");
  studentList.push_back("B045090034");
  studentList.push_back("B024020008");
  studentList.push_back("B024020020");
  studentList.push_back("B024020029");
  studentList.push_back("B034020019");
  
  generateStudent(studentList);
  
  return EXIT_SUCCESS;
}


void generateStudent(std::vector<string> & studentList) {
  std::vector<string> pwdList;
  std::vector<string> finderList;
  
  for (int i = 0; i < studentList.size(); i++) {
    string pwd;
    string dir;
    string studentID;
    
    for (int j = 0; j < PASSWORD_SIZE; j++) {
      char randC = RANDOM_NUMBER_GENERATION_TABLE[rand() % strlen(RANDOM_NUMBER_GENERATION_TABLE)];
      pwd.push_back(randC);
    }
    studentID = studentList[i];
    dir.append(ROOT_DIR);
    dir.append(studentID);
  
    pwdList.push_back(pwd);
    finderList.push_back(dir);
  }

  if (studentList.size() != 0 && pwdList.size() != 0 && finderList.size() != 0) {
    encrptyPassword(studentList, pwdList, finderList, printlnResult);
  }
}


void printlnResult(
      std::vector<string> & studentList,
      std::vector<string> & pwdList,
      std::vector<string> & md5PwdList,
      std::vector<string> & finderList) {

  std::fstream fp;
  fp.open("result.xml", std::fstream::app | std::fstream::out);
  if (!fp) {
    cout << "Fail to open result.xml" << endl;
  }
  for (int i = 0; i < studentList.size(); i++) {
    fp << "Student ID: " << studentList[i]
       << ", pwd: " << pwdList[i]
       << ", md5: " << md5PwdList[i]
       << ", dir: " << finderList[i] << endl;
  }
  fp.close();
}

void encrptyPassword(
      std::vector<string> & studentList,
      std::vector<string> & pwdList,
      std::vector<string> & finderList,
      void (*result)(
        std::vector<string> & sudentList,
        std::vector<string> & pwdList,
        std::vector<string> & md5PwdList,
        std::vector<string> & finderList)
      )
{
  
  std::vector<string> md5PwdList;
  if (result != NULL) {
    for (int i = 0; i < studentList.size(); i++)
        md5PwdList.push_back(md5(pwdList[i]));

    result(studentList, pwdList, md5PwdList, finderList);
    createUser(studentList, md5PwdList, finderList);
  }
}


void createUser(
      std::vector<string> & studentList,
      std::vector<string> & md5PwdList,
      std::vector<string> & finderList)
{
  
  file<> ftpServerFile(FILEZILLA_SERVER_PATH.c_str());
  xml_document<> ftpServerXML;
  ftpServerXML.parse<0>(ftpServerFile.data());

  xml_node<> *rootNode = ftpServerXML.first_node();
  
  xml_node<> *UsersNode = rootNode->first_node("Users");
  
  for (int i = 0; i < studentList.size(); i++) {

    // User
    xml_node<> *userNode = ftpServerXML.allocate_node(node_element, "User");
    userNode->append_attribute(ftpServerXML.allocate_attribute("Name", studentList[i].c_str()));
  
    xml_node<> *optionPassNode = ftpServerXML.allocate_node(node_element, "Option", md5PwdList[i].c_str());
    optionPassNode->append_attribute(ftpServerXML.allocate_attribute("Name", "Pass"));
  
    // Group
    xml_node<> *optionGroupNode = ftpServerXML.allocate_node(node_element, "Option");
    optionGroupNode->append_attribute(ftpServerXML.allocate_attribute("Name", "Group"));
  
    // Bypass
    xml_node<> *optionBSUNode = ftpServerXML.allocate_node(node_element, "Option", "0");
    optionBSUNode->append_attribute(ftpServerXML.allocate_attribute("Name", "Bypass server userlimit"));
  
    // User Limit
    xml_node<> *optionUserLimitNode = ftpServerXML.allocate_node(node_element, "Option", "0");
    optionUserLimitNode->append_attribute(ftpServerXML.allocate_attribute("Name", "User Limit"));
  
    // IP Limit
    xml_node<> *optionIPLimitNode = ftpServerXML.allocate_node(node_element, "Option", "0");
    optionIPLimitNode->append_attribute(ftpServerXML.allocate_attribute("Name", "IP Limit"));
  
    //Enabled
    xml_node<> *optionEnabledNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    optionEnabledNode->append_attribute(ftpServerXML.allocate_attribute("Name", "Enabled"));
  
    //Comments
    xml_node<> *optionCommentsNode = ftpServerXML.allocate_node(node_element, "Option");
    optionCommentsNode->append_attribute(ftpServerXML.allocate_attribute("Name", "Comments"));
  
    //ForceSsl
    xml_node<> *optionForceSslNode = ftpServerXML.allocate_node(node_element, "Option", "0");
    optionForceSslNode->append_attribute(ftpServerXML.allocate_attribute("Name", "ForceSsl"));
  
    userNode->append_node(optionPassNode);
    userNode->append_node(optionGroupNode);
    userNode->append_node(optionBSUNode);
    userNode->append_node(optionUserLimitNode);
    userNode->append_node(optionIPLimitNode);
    userNode->append_node(optionEnabledNode);
    userNode->append_node(optionCommentsNode);
    userNode->append_node(optionForceSslNode);
  
    UsersNode->append_node(userNode);
  
    xml_node<> *ipFilterNode = ftpServerXML.allocate_node(node_element, "IpFilter");
    xml_node<> *disallowedNode = ftpServerXML.allocate_node(node_element, "Disallowed");
    xml_node<> *allowedNode = ftpServerXML.allocate_node(node_element, "Allowed");
  
    ipFilterNode->append_node(disallowedNode);
    ipFilterNode->append_node(allowedNode);
    userNode->append_node(ipFilterNode);
  
    //Permissions
    xml_node<> *permissionsNode = ftpServerXML.allocate_node(node_element, "Permissions");
  
    //Permission
    xml_node<> *permissionNode = ftpServerXML.allocate_node(node_element, "Permission");
    permissionNode->append_attribute(ftpServerXML.allocate_attribute("Dir", finderList[i].c_str()));
  
    // FileRead
    xml_node<> *permissionOptionFileReadNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionFileReadNode->append_attribute(ftpServerXML.allocate_attribute("Name", "FileRead"));
  
    // FileWrite
    xml_node<> *permissionOptionFileWriteNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionFileWriteNode->append_attribute(ftpServerXML.allocate_attribute("Name", "FileWrite"));
  
    // FileDelete
    xml_node<> *permissionOptionFileDeleteNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionFileDeleteNode->append_attribute(ftpServerXML.allocate_attribute("Name", "FileDelete"));
  
    // FileAppend
    xml_node<> *permissionOptionFileAppendNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionFileAppendNode->append_attribute(ftpServerXML.allocate_attribute("Name", "FileAppend"));
  
    //DirCreate
    xml_node<> *permissionOptionDirCreateNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionDirCreateNode->append_attribute(ftpServerXML.allocate_attribute("Name", "DirCreate"));
  
    //DirDelete
    xml_node<> *permissionOptionDirDeleteNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionDirDeleteNode->append_attribute(ftpServerXML.allocate_attribute("Name", "DirDelete"));
  
    //DirList
    xml_node<> *permissionOptionDirListNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionDirListNode->append_attribute(ftpServerXML.allocate_attribute("Name", "DirList"));
  
    //DirSubdirs
    xml_node<> *permissionOptionDirSubdirsNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionDirSubdirsNode->append_attribute(ftpServerXML.allocate_attribute("Name", "DirSubdirs"));
  
    //IsHome
    xml_node<> *permissionOptionIsHomeNode = ftpServerXML.allocate_node(node_element, "Option", "1");
    permissionOptionIsHomeNode->append_attribute(ftpServerXML.allocate_attribute("Name", "IsHome"));
  
    //AutoCreate
    xml_node<> *permissionOptionAutoCreateNode = ftpServerXML.allocate_node(node_element, "Option", "0");
    permissionOptionAutoCreateNode->append_attribute(ftpServerXML.allocate_attribute("Name", "AutoCreate"));
  
    permissionNode->append_node(permissionOptionFileReadNode);
    permissionNode->append_node(permissionOptionFileWriteNode);
    permissionNode->append_node(permissionOptionFileDeleteNode);
    permissionNode->append_node(permissionOptionFileAppendNode);
    permissionNode->append_node(permissionOptionDirCreateNode);
    permissionNode->append_node(permissionOptionDirDeleteNode);
    permissionNode->append_node(permissionOptionDirListNode);
    permissionNode->append_node(permissionOptionDirSubdirsNode);
    permissionNode->append_node(permissionOptionIsHomeNode);
    permissionNode->append_node(permissionOptionAutoCreateNode);
  
    permissionsNode->append_node(permissionNode);
    userNode->append_node(permissionsNode);
  
    // SpeedLimits
    xml_node<> *speedLimitsNode = ftpServerXML.allocate_node(node_element, "SpeedLimits");
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("DlType", "0"));
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("DlLimit", "10"));
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("ServerDlLimitBypass", "0"));
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("UlType", "0"));
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("UlLimit", "10"));
    speedLimitsNode->append_attribute(ftpServerXML.allocate_attribute("ServerUlLimitBypass", "0"));
  
    // Download
    xml_node<> *downloadNode = ftpServerXML.allocate_node(node_element, "Download");
  
    // Upload
    xml_node<> *uploadNode = ftpServerXML.allocate_node(node_element, "Upload");
  
    speedLimitsNode->append_node(downloadNode);
    speedLimitsNode->append_node(uploadNode);
  
    userNode->append_node(speedLimitsNode);
  }

  std::string text;
  rapidxml::print(std::back_inserter(text), ftpServerXML, 0);
  //  rapidxml::print(std::back_inserter(text), ftpServerXML, 0);
  //  cout << text << endl;
  
  std::fstream fp;
  fp.open("FileZilla_new_Server.xml", std::fstream::app | std::fstream::out);
  if (!fp) {
    cout << "Fail to open result.xml" << endl;
  }
  fp << text << endl;
  fp.close();
}

