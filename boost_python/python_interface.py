import pyplusplus.module_builder
import os
import sys

def CreateInterfaceCpp(file_list, cur_gccxml_path, target_module_name, 
						current_dir, out_dir):
	mb = pyplusplus.module_builder.module_builder_t(files = file_list,
										gccxml_path = cur_gccxml_path)
	mb.build_code_creator(module_name = target_module_name)
	mb.code_creator.user_defined_directories.append(current_dir)
	mb.write_module(out_dir)

def Main():
	target_module_name = "libtest_py"
	current_dir = os.path.abspath('.')
	out_dir = current_dir + '/test_py.cc'
	file_list = ['test.h']
	cur_gccxml_path = '/usr/bin/gccxml'
	CreateInterfaceCpp(file_list, cur_gccxml_path, target_module_name, 
						current_dir, out_dir)

if __name__ == '__main__':
	Main()