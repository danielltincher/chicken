#include "ChickenApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<ChickenApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ChickenApp::ChickenApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ChickenApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ChickenApp::associateSyntax(_syntax, _action_factory);
}

ChickenApp::~ChickenApp()
{
}

// External entry point for dynamic application loading
extern "C" void ChickenApp__registerApps() { ChickenApp::registerApps(); }
void
ChickenApp::registerApps()
{
  registerApp(ChickenApp);
}

// External entry point for dynamic object registration
extern "C" void ChickenApp__registerObjects(Factory & factory) { ChickenApp::registerObjects(factory); }
void
ChickenApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void ChickenApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { ChickenApp::associateSyntax(syntax, action_factory); }
void
ChickenApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
