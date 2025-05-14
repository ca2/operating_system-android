// Created by camilo on 2022-05-06 03:49 <3ThomasBorregaardSorensen!!
#pragma once


class asset :
   virtual public ::particle

{
public:


   AAsset* m_passet;


   asset(AAsset* passet);
   ~asset() override;


   void get_pointers(const char*& pstart, const char* & pend);


};



