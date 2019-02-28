
project := "MarshmallowProject".

project_version := "0.1.171".

buildfile_version := "1.0".

url_to_src := "https://github.com/JHG777000/marshmallow/archive/master.zip".

build MarshmallowBuild.

 options.

  on test_enable("-t", "--test", "Enable marshmallow tests.").

  on toolchain_select("-s", "--select_toolchain=tool", "Select toolchain.").

  on leak_test_enable("-l", "--leak_test", "Enable marshmallow leak tests.").

  on cfg_test_enable("-c", "--cfg_test", "Enable marshmallow cfg tests.").

 end options.

 get test_enable.

 get toolchain_select.

 get leak_test_enable.

 get cfg_test_enable.

 if ( toolchain_select == nil ).

  var toolchain_select := "clang".

 end if.

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,nil).

 grab RKLib from RKLibProject.

 files Files("src.directories").

 files Main("main.directories").

 if ( cfg_test_enable ).

  message("cfg_tests").

  files Main("tests/cfg_tests.c").

 end if.

 sources Source(Files,Main,RKLib).

 make filepath include_path from "resources" to "src".

 make filepath rklib_include_path from "resources" to "include" from RKLibProject.

 compiler CompilerFlags("-Wall", "-I " + include_path, "-I " + rklib_include_path).

 toolchain ToolChain(toolchain_select,CompilerFlags).

 output marshmallow("application",Source,ToolChain).

 copy_output(marshmallow,"project").

 if ( test_enable ).

  message("Running marshmallow tests...").

  make filepath marshmallow_path from "project" to "marshmallow".

  make filepath helloworld_msrc_path from "resources" to "helloworld.msrc".

  make filepath marshmallow_c_output_path from "resources" to "helloworld_C_output".

  run(marshmallow_path + " " + helloworld_msrc_path + " " + marshmallow_c_output_path).

  files Files("helloworld_C_output/module_mymod.c").

  sources Source(Files).

  compiler CompilerFlags("-w").

  toolchain ToolChain(toolchain_select,CompilerFlags).

  output marshmallow_test("application",Source,ToolChain).

  launch(marshmallow_test).

  message("Ran marshmallow tests.").

 end if.

if ( leak_test_enable ).

 make filepath marshmallow_path from "project" to "marshmallow".

 make filepath helloworld_msrc_path from "resources" to "helloworld.msrc".

 make filepath marshmallow_c_output_path from "resources" to "helloworld_C_output".

 make filepath trace_file_path from "project" to "marshmallow.trace".

  if ( !cfg_test_enable ).

   run("instruments -t \"Leaks\" -D" + " " + trace_file_path +
   " " +  marshmallow_path + " " + helloworld_msrc_path + " " + marshmallow_c_output_path).

 end if.

  if ( cfg_test_enable ).

   run("instruments -t \"Leaks\" -D" + " " + trace_file_path + " " + marshmallow_path ).

  end if.

  run("open /Applications/Xcode.app/Contents/Applications/Instruments.app" + " " + trace_file_path).

end if.

end build.

build clean_build.

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,"-b clean_build").

 message("Cleaning marshmallow...").

 clean("build").

end build.

default MarshmallowBuild.
