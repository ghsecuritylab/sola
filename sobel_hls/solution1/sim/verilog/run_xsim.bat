
set PATH=
call L:/Xilinx_201802/Vivado/2018.2/bin/xelab xil_defaultlib.apatb_sobel_filter_top glbl -prj sobel_filter.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "L:/Xilinx_201802/Vivado/2018.2/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s sobel_filter -debug wave
call L:/Xilinx_201802/Vivado/2018.2/bin/xsim --noieeewarnings sobel_filter -tclbatch sobel_filter.tcl

