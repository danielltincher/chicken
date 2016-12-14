#ifndef CHICKENAPP_H
#define CHICKENAPP_H

#include "MooseApp.h"

class ChickenApp;

template<>
InputParameters validParams<ChickenApp>();

class ChickenApp : public MooseApp
{
public:
  ChickenApp(InputParameters parameters);
  virtual ~ChickenApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CHICKENAPP_H */
