# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\adam\\Desktop\\CPE 301 Final Project\\cpe310_simon_says_final\\out\\CPE310_Simon_Says_Final\\default.eep"
  "C:\\Users\\adam\\Desktop\\CPE 301 Final Project\\cpe310_simon_says_final\\out\\CPE310_Simon_Says_Final\\default.hex"
  "C:\\Users\\adam\\Desktop\\CPE 301 Final Project\\cpe310_simon_says_final\\out\\CPE310_Simon_Says_Final\\default.lss"
  "C:\\Users\\adam\\Desktop\\CPE 301 Final Project\\cpe310_simon_says_final\\out\\CPE310_Simon_Says_Final\\default.srec"
  "C:\\Users\\adam\\Desktop\\CPE 301 Final Project\\cpe310_simon_says_final\\out\\CPE310_Simon_Says_Final\\default.usersignatures"
  )
endif()
