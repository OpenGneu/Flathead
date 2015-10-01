
#include "stdafx.h"

#include "Utility/Configuration.h"
#include "Enumerations/LogLevels.h"

#include <strsafe.h>

using namespace Gneu;
using namespace Gneu::Utility;

void DefaultLogFn(int type, const char *msg)
{
	switch (type)
	{
	case LogLevels::Assert:
		printf("Assert: %s\n", msg);
		break;
	case LogLevels::Error:
		printf("Error: %s\n", msg);
		break;
	case LogLevels::Warn:
		printf("Warn: %s\n", msg);
		break;
	case LogLevels::Info:
		printf("Info: %s\n", msg);
		break;
	case LogLevels::Log:
	default:
		printf("Log: %s\n", msg);
		break;
	}
}

/// <summary>
/// Default Constructor
/// </summary>
Configuration::Configuration()
{
	Path("lib/");
	Bootstrap("lib/core/bootstrap.js");
	LoggingFn(DefaultLogFn);

	EnableHotReload(true);

	EnableESStaging(false);

	EnableHarmony(false);

	EnableHarmonyArrays(false);
	EnableHarmonyCollections(false);
	EnableHarmonyGenerators(false);
	EnableHarmonyIteration(false);
	EnableHarmonyMaths(false);
	EnableHarmonyModules(false);
	EnableHarmonyNumericLiterals(false);
	EnableHarmonyTypeOf(false);
	EnableHarmonyObservation(false);
	EnableHarmonyProxies(false);
	EnableHarmonyScoping(false);
	EnableHarmonyStrings(false);
	EnableHarmonySymbols(false);
	EnableHarmonyDestructuring(false);

	AlwaysStrict(false);

	ShouldInitializeImmediately(true);
}

/// <summary>
/// Copy Constructor
/// </summary>
Configuration::Configuration(Configuration *cfg)
{
	EnableHotReload(cfg->EnableHotReload());
	AlwaysStrict(cfg->AlwaysStrict());
	
	Path(cfg->Path());
	Bootstrap(cfg->Bootstrap());
	
	// Enable components that are ready for prime time
	EnableESStaging(cfg->EnableESStaging());

	// Enable Harmony 
	EnableHarmony(cfg->EnableHarmony());

	// Individual Options
	EnableHarmonyArrays(cfg->EnableHarmonyArrays());
	EnableHarmonyCollections(cfg->EnableHarmonyCollections());
	EnableHarmonyGenerators(cfg->EnableHarmonyGenerators());
	EnableHarmonyIteration(cfg->EnableHarmonyIteration());
	EnableHarmonyMaths(cfg->EnableHarmonyMaths());
	EnableHarmonyModules(cfg->EnableHarmonyModules());
	EnableHarmonyNumericLiterals(cfg->EnableHarmonyNumericLiterals());
	EnableHarmonyTypeOf(cfg->EnableHarmonyTypeOf());
	EnableHarmonyObservation(cfg->EnableHarmonyObservation());
	EnableHarmonyProxies(cfg->EnableHarmonyProxies());
	EnableHarmonyScoping(cfg->EnableHarmonyScoping());
	EnableHarmonyStrings(cfg->EnableHarmonyStrings());
	EnableHarmonySymbols(cfg->EnableHarmonySymbols());
	EnableHarmonyDestructuring(cfg->EnableHarmonyDestructuring());
}

/// <summary>
/// Gets the logging function for v8 to use.
/// </summary>
/// <returns>reference to the logging function</returns>
LoggingFunction Configuration::LoggingFn()
{
	return *loggingFunction;
}

/// <summary>
/// Sets the logging function for v8 to use.
/// </summary>
/// <param name="fn">function to use for logging</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::LoggingFn(LoggingFunction fn)
{
	loggingFunction = fn;

	return this;
}

/// <summary>
/// Gets the path to be used for library lookup
/// </summary>
/// <returns>reference to the path</returns>
const char *Configuration::Bootstrap()
{
	return bootstrap;
}

/// <summary>
/// Sets the Path to the bootstrap library as a relative path from the application.
/// </summary>
/// <param name="_bootstrap">string representation of path for library lookup</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::Bootstrap(const char *_bootstrap)
{
	StringCchCopyA(bootstrap, 2048, _bootstrap);

	return this;
}

/// <summary>
/// Gets the path to be used for library lookup
/// </summary>
/// <returns>reference to the path</returns>
const char *Configuration::Path()
{
	return path;
}

/// <summary>
/// Sets the Path for library lookup
/// </summary>
/// <param name="_path">string representation of path for library lookup</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::Path(const char *_path)
{
	StringCchCopyA(path, 2048, _path);

	return this;
}			

/// <summary>
/// Sets the flags for Harmony being enabled
/// </summary>
/// <returns>boolean of Harmony being enabled</returns>
bool Configuration::EnableHarmony()
{
	return Harmony;
}

/// <summary>
/// Gets the flags for Harmony being enabled
/// </summary>
/// <param name="_harmony">boolean of Harmony being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmony(bool _harmony)
{
	Harmony = _harmony;

	return this;
}

/// <summary>
/// Sets the flags for hot reloading being enabled
/// </summary>
/// <returns>boolean of hot reloading being enabled</returns>
bool Configuration::EnableHotReload()
{
	return HotReload;
}

/// <summary>
/// Gets the flags for Hot Reloading being enabled
/// </summary>
/// <param name="_hotReload">boolean of Hot Reloading being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHotReload(bool _hotReload)
{
	HotReload = _hotReload;

	return this;
}

/// <summary>
/// Sets the flags for ES6 Staging being enabled
/// </summary>
/// <returns>boolean of ES6 Staging being enabled</returns>
bool Configuration::EnableESStaging()
{
	return ESStaging;
}

/// <summary>
/// Gets the flags for ES6 Staging being enabled
/// </summary>
/// <param name="_ESStaging">boolean of ES6 Staging being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableESStaging(bool _ESStaging)
{
	ESStaging = _ESStaging;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Generators being enabled
/// </summary>
/// <returns>boolean of Harmony Generators being enabled</returns>
bool Configuration::EnableHarmonyGenerators()
{
	return HarmonyGenerators;
}

/// <summary>
/// Gets the flags for Harmony Generators being enabled
/// </summary>
/// <param name="_HarmonyGenerators">boolean of Harmony Generators being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyGenerators(bool _HarmonyGenerators)
{
	HarmonyGenerators = _HarmonyGenerators;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Collections being enabled
/// </summary>
/// <returns>boolean of Harmony Collections being enabled</returns>
bool Configuration::EnableHarmonyCollections()
{
	return HarmonyCollections;
}

/// <summary>
/// Gets the flags for Harmony Collections being enabled
/// </summary>
/// <param name="_HarmonyCollections">boolean of Harmony Collections being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyCollections(bool _HarmonyCollections)
{
	HarmonyCollections = _HarmonyCollections;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Proxies being enabled
/// </summary>
/// <returns>boolean of Harmony Proxies being enabled</returns>
bool Configuration::EnableHarmonyProxies()
{
	return HarmonyProxies;
}

/// <summary>
/// Gets the flags for Harmony Proxies being enabled
/// </summary>
/// <param name="_HarmonyProxies">boolean of Harmony Proxies being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyProxies(bool _HarmonyProxies)
{
	HarmonyProxies = _HarmonyProxies;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Modules being enabled
/// </summary>
/// <returns>boolean of Harmony Modules being enabled</returns>
bool Configuration::EnableHarmonyModules()
{
	return HarmonyModules;
}

/// <summary>
/// Gets the flags for Harmony Modules being enabled
/// </summary>
/// <param name="_HarmonyModules">boolean of Harmony Modules being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyModules(bool _HarmonyModules)
{
	HarmonyModules = _HarmonyModules;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Scoping being enabled
/// </summary>
/// <returns>boolean of Harmony Scoping being enabled</returns>
bool Configuration::EnableHarmonyScoping()
{
	return HarmonyScoping;
}

/// <summary>
/// Gets the flags for Harmony Scoping being enabled
/// </summary>
/// <param name="_HarmonyScoping">boolean of Harmony Scoping being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyScoping(bool _HarmonyScoping)
{
	HarmonyScoping = _HarmonyScoping;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Observation being enabled
/// </summary>
/// <returns>boolean of Harmony Observation being enabled</returns>
bool Configuration::EnableHarmonyObservation()
{
	return HarmonyObservation;
}

/// <summary>
/// Gets the flags for Harmony Observation being enabled
/// </summary>
/// <param name="_HarmonyObservation">boolean of Harmony Observation being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyObservation(bool _HarmonyObservation)
{
	HarmonyObservation = _HarmonyObservation;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Symbols being enabled
/// </summary>
/// <returns>boolean of Harmony Symbols being enabled</returns>
bool Configuration::EnableHarmonySymbols()
{
	return HarmonySymbols;
}

/// <summary>
/// Gets the flags for Harmony Symbols being enabled
/// </summary>
/// <param name="_HarmonySymbols">boolean of Harmony Symbols being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonySymbols(bool _HarmonySymbols)
{
	HarmonySymbols = _HarmonySymbols;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Iteration being enabled
/// </summary>
/// <returns>boolean of Harmony Iteration being enabled</returns>
bool Configuration::EnableHarmonyIteration()
{
	return HarmonyIteration;
}

/// <summary>
/// Gets the flags for Harmony Iteration being enabled
/// </summary>
/// <param name="_HarmonyIteration">boolean of Harmony Iteration being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyIteration(bool _HarmonyIteration)
{
	HarmonyIteration = _HarmonyIteration;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Maths being enabled
/// </summary>
/// <returns>boolean of Harmony Maths being enabled</returns>
bool Configuration::EnableHarmonyMaths()
{
	return HarmonyMaths;
}

/// <summary>
/// Gets the flags for Harmony Maths being enabled
/// </summary>
/// <param name="_HarmonyMaths">boolean of Maths Iteration being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyMaths(bool _HarmonyMaths)
{
	HarmonyMaths = _HarmonyMaths;
	return this;
}

/// <summary>
/// Sets the flags for Harmony Strings being enabled
/// </summary>
/// <returns>boolean of Harmony Strings being enabled</returns>
bool Configuration::EnableHarmonyStrings()
{
	return HarmonyStrings;
}

/// <summary>
/// Gets the flags for Harmony Strings being enabled
/// </summary>
/// <param name="_HarmonyStrings">boolean of Strings being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyStrings(bool _HarmonyStrings)
{
	HarmonyStrings = _HarmonyStrings;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Arrays being enabled
/// </summary>
/// <returns>boolean of Harmony Arrays being enabled</returns>
bool Configuration::EnableHarmonyArrays()
{
	return HarmonyArrays;
}

/// <summary>
/// Gets the flags for Harmony Arrays being enabled
/// </summary>
/// <param name="_HarmonyArrays">boolean of Arrays being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyArrays(bool _HarmonyArrays)
{
	HarmonyArrays = _HarmonyArrays;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Numeric Literals being enabled
/// </summary>
/// <returns>boolean of Harmony Numeric Literals being enabled</returns>
bool Configuration::EnableHarmonyNumericLiterals()
{
	return HarmonyNumericLiterals;
}

/// <summary>
/// Gets the flags for Harmony Numeric Literals being enabled
/// </summary>
/// <param name="_HarmonyNumericLiterals">boolean of Numeric Literals being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyNumericLiterals(bool _HarmonyNumericLiterals)
{
	HarmonyNumericLiterals = _HarmonyNumericLiterals;

	return this;
}

/// <summary>
/// Sets the flags for Harmony TypeOf being enabled
/// </summary>
/// <returns>boolean of Harmony TypeOf being enabled</returns>
bool Configuration::EnableHarmonyTypeOf()
{
	return HarmonyTypeOf;
}

/// <summary>
/// Gets the flags for Harmony TypeOf being enabled
/// </summary>
/// <param name="_HarmonyTypeOf">boolean of TypeOf being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyTypeOf(bool _HarmonyTypeOf)
{
	HarmonyTypeOf = _HarmonyTypeOf;

	return this;
}

/// <summary>
/// Sets the flags for Harmony Destructuring being enabled
/// </summary>
/// <returns>boolean of Harmony Destructuring being enabled</returns>
bool Configuration::EnableHarmonyDestructuring()
{
	return HarmonyDestructuring;
}

/// <summary>
/// Gets the flags for Harmony Destructuring being enabled
/// </summary>
/// <param name="_HarmonyDestructuring">boolean of Destructuring being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::EnableHarmonyDestructuring(bool _HarmonyDestructuring)
{
	HarmonyDestructuring = _HarmonyDestructuring;

	return this;
}

/// <summary>
/// Sets the flags for initializing flathead immediately being enabled
/// </summary>
/// <returns>boolean for whether Flathead should initialize immediately</returns>
bool Configuration::ShouldInitializeImmediately()
{
	return InitializeImmediately;
}

/// <summary>
/// Gets the flags for initializing flathead immediately being enabled
/// </summary>
/// <param name="_InitializeImmediately">boolean of immediate initialization being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::ShouldInitializeImmediately(bool _InitializeImmediately)
{
	InitializeImmediately = _InitializeImmediately;

	return this;
}

/// <summary>
/// Sets the flags for setting strict mode by default being enabled
/// </summary>
/// <returns>boolean for whether Flathead should initialize immediately</returns>
bool Configuration::AlwaysStrict()
{
	return Strict;
}

/// <summary>
/// Gets the flags for setting strict mode by default being enabled
/// </summary>
/// <param name="_alwaysStrict">boolean of strict mode by default being enabled</param>
/// <returns>reference to this configuration object for method chaining</returns>
Configuration *Configuration::AlwaysStrict(bool _alwaysStrict)
{
	Strict = _alwaysStrict;

	return this;
}