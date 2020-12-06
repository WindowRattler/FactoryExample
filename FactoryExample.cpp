//BenjaminKramer
//12-6-2020

//An example of a Factory Design Pattern
//Made to Describe Other Design Patterns
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DesignPattern {
  public:
  
    // Factory Method, note it's static
    static DesignPattern *make_designPattern(string choice);
  
    // method that we will use polymorphically per design pattern
    virtual void io() = 0;
    
    // Note: need to specify an explicicit default destructor
    virtual ~DesignPattern() = default;
};

//Class accessed to describe a factory design pattern
//to the user per their input request
class FactoryExample: public DesignPattern {
  public:
    void io() {
        cout << "Factory Example -> found at:" << endl;
	cout << "https://sourcemaking.com/design_patterns/factory_method" << endl;
    }
};

//Class accessed to describe a builder design pattern
//to the user per their input request
class BuilderExample: public DesignPattern {
  public:
    void io() {
        cout << "Builder Example -> found at:" << endl;
	cout << "https://refactoring.guru/design-patterns/builder" << endl;
    }
};

//Class accessed to describe an adapter design pattern
//to the user per their input request
class AdapterExample: public DesignPattern {
  public:
    void io() {
        cout << "Adapter Example -> found at:" << endl;
	cout << "https://www.geeksforgeeks.org/adapter-pattern/" << endl;
    }
};


// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
DesignPattern *DesignPattern::make_designPattern(string choice) {
  if (choice ==  "factory")
    return new FactoryExample;
  else if (choice == "builder")
    return new BuilderExample;
  else
    return new AdapterExample;
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main() {
  vector<DesignPattern*> patterns;
  string choice;
  cout << "This Program gives URLs describing three design patterns."
  << endl;
  cout << "--------Adapter----------Builder---------Factory---------" << endl;
  while (true) {
    cout << "Enter Design Patterns (Adapter is default) or 0 if done: ";
    cin >> choice;
    if (choice == "0") break;
    patterns.push_back(DesignPattern::make_designPattern(choice));
  }
  for (int i = 0; i < patterns.size(); i++) {
    patterns[i]->io();
  }
  for (int i = 0; i < patterns.size(); i++) {
    delete patterns[i];
  }
}
