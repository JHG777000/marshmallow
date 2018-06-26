
project := "MarshmallowProject".

project_version := "0.1.1".

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

 files Files("src.directory").

 sources Source(Files,RKLib).

 make filepath rklib_include_path from "resources" to "include" from RKLibProject.

 compiler CompilerFlags("-Wall", "-I " + rklib_include_path).

 toolchain ToolChain(toolchain_select,CompilerFlags).

 output marshmallow("application",Source,ToolChain).

 copy_output(marshmallow,"project").

 if ( test_enable ).

  message("Running marshmallow tests...").

  make filepath marshmallow_path from "project" to "marshmallow".

  make filepath hellowolrd_msrc_path from "resources" to "hellowolrd.msrc".

  make filepath marshmallow_c_output_path from "resources" to "hellowolrd_C_output.c".

  run(marshmallow_path + " " + hellowolrd_msrc_path + " " + marshmallow_c_output_path).

  files Files("hellowolrd_C_output.c").

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



