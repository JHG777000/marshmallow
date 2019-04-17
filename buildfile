project := "MarshmallowProject".

project_version := "0.1.179".

buildfile_version := "1.0".

url_to_src := "https://github.com/JHG777000/marshmallow/archive/master.zip".

build MarshmallowBuild.

 options.

  on test_enable("-t", "--test", "Enable marshmallow tests.").

  on toolchain_select("-s", "--select_toolchain=tool", "Select toolchain.").

  on leak_test_enable("-l", "--leak_test", "Enable marshmallow leak tests.").

  on cfg_test_enable("-c", "--cfg_test", "Enable marshmallow cfg tests.").

  on tree_sitter_enable("-p", "--parser_tree_sitter", "Enable marshmallow tree sitter tests.").

 end options.

 get test_enable.

 get toolchain_select.

 get leak_test_enable.

 get cfg_test_enable.

 get tree_sitter_enable.

 if ( leak_test_enable && !is_mac ).

  message("leak_test is a macOS only feature.").

  bool leak_test_enable := false.

 end if.

 if ( toolchain_select == nil ).

  var toolchain_select := "clang".

 end if.

 url tree_sitter_marshmallow_buildfile("https://raw.githubusercontent.com/JHG777000/tree-sitter-marshmallow/master/buildfile").

 subproject tree_sitter_marshmallow_project("local",tree_sitter_marshmallow_buildfile,nil).

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,nil).

 grab RKLib from RKLibProject.

 grab tree_sitter_project from tree_sitter_marshmallow_project.

 grab tree_sitter_marshmallow_parser_lib from tree_sitter_marshmallow_project.

 files Files("src.directories").

 files Main("main.directories").

 if ( cfg_test_enable ).

  message("Running marshmallow cfg_tests...").

  files Main("tests/cfg_tests.c").

 end if.

 if ( tree_sitter_enable ).

  files Main("tests/tree_sitter_tests.c").

  sources Source(Files,Main,tree_sitter_marshmallow_parser_lib,RKLib).

 end if.

 if ( !tree_sitter_enable ).

  sources Source(Files,Main,RKLib).

 end if.

 make filepath include_path from "resources" to "src".

 make filepath rklib_include_path from "resources" to "include" from RKLibProject.

 make filepath tree_sitter_marshmallow_include from "resources" to "lib/include" from tree_sitter_project.

 compiler CompilerFlags("-Wall", "-I " + include_path, "-I " + rklib_include_path, "-I " + tree_sitter_marshmallow_include).

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

if ( cfg_test_enable && !leak_test_enable  ).

 launch(marshmallow).

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

   run("instruments -t \"Leaks\" -D" + " " + trace_file_path + " " + marshmallow_path).

  end if.

  run("open /Applications/Xcode.app/Contents/Applications/Instruments.app" + " " + trace_file_path).

end if.

end build.

build clean_build.

 url tree_sitter_marshmallow_buildfile("https://raw.githubusercontent.com/JHG777000/tree-sitter-marshmallow/master/buildfile").

 subproject tree_sitter_marshmallow_project("local",tree_sitter_marshmallow_buildfile,"-b clean_build").

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,"-b clean_build").

 message("Cleaning marshmallow...").

 clean("build").

end build.

default MarshmallowBuild.
