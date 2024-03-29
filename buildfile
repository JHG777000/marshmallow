project := "MarshmallowProject".

project_version := "0.1.248".

buildfile_version := "1.0".

url_to_src := "https://github.com/JHG777000/marshmallow/archive/main.zip".

build MarshmallowBuild.

 options.

  on test_enable("-t", "--test", "Enable marshmallow tests.").

  on toolchain_select("-s", "--select_toolchain=tool", "Select toolchain.").

  on cfg_test_enable("-c", "--cfg_test", "Enable marshmallow cfg tests.").

  on mib_test_enable("-m", "--mib_test_enable", "Enable marshmallow mib tests.").

  on mab_test_enable("-a", "--mab_test_enable", "Enable marshmallow mab tests.").

  on tree_sitter_enable("-p", "--parser_tree_sitter", "Enable marshmallow tree sitter tests.").

 end options.

 get test_enable.

 get toolchain_select.

 get cfg_test_enable.

 get mib_test_enable.

 get mab_test_enable.

 get tree_sitter_enable.

 if ( toolchain_select == nil ).

  var toolchain_select := "clang".

 end if.

 url tree_sitter_marshmallow_buildfile("https://raw.githubusercontent.com/JHG777000/tree-sitter-marshmallow/main/buildfile").

 subproject tree_sitter_marshmallow_project("local",tree_sitter_marshmallow_buildfile,nil).

 url URLForFudge("https://raw.githubusercontent.com/JHG777000/Fudge/main/buildfile").

 subproject FudgeProject("local",URLForFudge,nil).

 grab Fudge from FudgeProject.

 grab RKLibProject from FudgeProject.

 grab RKLib from RKLibProject.

 grab tree_sitter_project from tree_sitter_marshmallow_project.

 grab tree_sitter_dep_utf8proc_project from tree_sitter_marshmallow_project.

 grab tree_sitter_marshmallow_parser_lib from tree_sitter_marshmallow_project.

 grab tree_sitter_lib from tree_sitter_project.

 files Files("src.directories").

 files Main("main.directories").

 if ( cfg_test_enable ).

  message("Running marshmallow cfg_tests...").

  files Main("tests/cfg_tests.c").

 end if.

 if ( mib_test_enable ).

  message("Running marshmallow mib_tests...").

  files Main("tests/mib_tests.c").

 end if.

 if ( mab_test_enable ).

  message("Running marshmallow mab_tests...").

  files Main("tests/mab_tests.c").

 end if.

 if ( tree_sitter_enable ).

  files Main("tests/tree_sitter_tests.c").

  sources Source(Files,Main,tree_sitter_marshmallow_parser_lib,tree_sitter_lib,Fudge,RKLib).

 end if.

 if ( !tree_sitter_enable ).

  sources Source(Files,Main,tree_sitter_marshmallow_parser_lib,tree_sitter_lib,Fudge,RKLib).

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

 if ( mib_test_enable ).

  make filepath marshmallow_path from "project" to "marshmallow".

  make filepath mib_output_path from "resources" to "tests/mib_C_output".

  run(marshmallow_path + " " + mib_output_path).

  files Files("tests/mib_C_output/module_mymod_mib.c").

  sources Source(Files).

  compiler CompilerFlags("-w").

  toolchain ToolChain(toolchain_select,CompilerFlags).

  output marshmallow_test("application",Source,ToolChain).

  launch(marshmallow_test).

  message("Ran mib tests.").

 end if.

 if ( mab_test_enable ).

  make filepath marshmallow_path from "project" to "marshmallow".

  make filepath mib_output_path from "resources" to "tests/mib_C_output".

  run(marshmallow_path + " " + mib_output_path).

  //files Files("tests/mib_C_output/module_mymod_mib.c").

  //sources Source(Files).

  //compiler CompilerFlags("-w").

  //toolchain ToolChain(toolchain_select,CompilerFlags).

  //output marshmallow_test("application",Source,ToolChain).

  //launch(marshmallow_test).

  message("Ran mab tests.").

 end if.

 if ( tree_sitter_enable ).

  make filepath marshmallow_path from "project" to "marshmallow".

  make filepath marshmallow_src_path from "resources" to "tests/test2.msrc" from tree_sitter_marshmallow_project.

  run(marshmallow_path + " " + marshmallow_src_path).

 end if.

if ( cfg_test_enable ).

 launch(marshmallow).

end if.

end build.

build clean_build.

 url tree_sitter_marshmallow_buildfile("https://raw.githubusercontent.com/JHG777000/tree-sitter-marshmallow/main/buildfile").

 subproject tree_sitter_marshmallow_project("local",tree_sitter_marshmallow_buildfile,"-b clean_build").

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/main/buildfile").

 subproject RKLibProject("local",URLForRKLib,"-b clean_build").

 message("Cleaning marshmallow...").

 clean("build").

end build.

default MarshmallowBuild.
