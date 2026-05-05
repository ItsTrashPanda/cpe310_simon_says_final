# The following variables contains the files used by the different stages of the build process.
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assemble)
set_source_files_properties(${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_assembleWithPreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../btn.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../i2c.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../lcd.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../spi.c")
set_source_files_properties(${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_compile_cpp)
set_source_files_properties(${CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_link)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_objcopy_ihex)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_objcopy_eep)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_objcopy_lss)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_objcopy_srec)
set(CPE310_Simon_Says_Final_default_default_AVR_GCC_FILE_TYPE_objcopy_sig)
set(CPE310_Simon_Says_Final_default_image_name "default.elf")
set(CPE310_Simon_Says_Final_default_image_base_name "default")

# The output directory of the final image.
set(CPE310_Simon_Says_Final_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/CPE310_Simon_Says_Final")

# The full path to the final image.
set(CPE310_Simon_Says_Final_default_full_path_to_image ${CPE310_Simon_Says_Final_default_output_dir}/${CPE310_Simon_Says_Final_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .lss
    .eep
    .srec
    .usersignatures)
list(TRANSFORM output_extensions PREPEND "${CPE310_Simon_Says_Final_default_output_dir}/${CPE310_Simon_Says_Final_default_image_base_name}")
