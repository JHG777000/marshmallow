
project := "MarshmallowProject".

project_version := "0.1.65".

buildfile_version := "1.0".

url_to_src := "https://github.com/JHG777000/marshmallow/archive/master.zip".

build MarshmallowBuild.

 options.

  on test_enable("-t", "--test", "Enable marshmallow tests.").

  on toolchain_select("-s", "--select_toolchain=tool", "Select toolchain.").

 end options.

 get test_enable.

 get toolchain_select.

 if ( toolchain_select == nil ).

  var toolchain_select := "clang".

 end if.

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,nil).

 grab RKLib from RKLibProject.

 files Files("src.directories").

 sources Source(Files,RKLib).

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

  make filepath marshmallow_c_output_path from "resources" to "helloworld_C_output.c".

  run(marshmallow_path + " " + helloworld_msrc_path + " " + marshmallow_c_output_path).

  files Files("helloworld_C_output.c").

  sources Source(Files).

  compiler CompilerFlags("-w").

  toolchain ToolChain(toolchain_select,CompilerFlags).

  output marshmallow_test("application",Source,ToolChain).

  launch(marshmallow_test).

  message("Ran marshmallow tests.").

 end if.

end build.

build clean_build.

 url URLForRKLib("https://raw.githubusercontent.com/JHG777000/RKLib/master/buildfile").

 subproject RKLibProject("local",URLForRKLib,"-b clean_build").

 message("Cleaning marshmallow...").

 clean("build").

end build.

default MarshmallowBuild.
