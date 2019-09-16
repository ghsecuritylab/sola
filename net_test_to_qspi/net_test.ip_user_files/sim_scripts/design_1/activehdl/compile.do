vlib work
vlib activehdl

vlib activehdl/xilinx_vip
vlib activehdl/xil_defaultlib
vlib activehdl/xpm
vlib activehdl/axi_infrastructure_v1_1_0
vlib activehdl/smartconnect_v1_0
vlib activehdl/axi_protocol_checker_v2_0_3
vlib activehdl/axi_vip_v1_1_3
vlib activehdl/processing_system7_vip_v1_0_5

vmap xilinx_vip activehdl/xilinx_vip
vmap xil_defaultlib activehdl/xil_defaultlib
vmap xpm activehdl/xpm
vmap axi_infrastructure_v1_1_0 activehdl/axi_infrastructure_v1_1_0
vmap smartconnect_v1_0 activehdl/smartconnect_v1_0
vmap axi_protocol_checker_v2_0_3 activehdl/axi_protocol_checker_v2_0_3
vmap axi_vip_v1_1_3 activehdl/axi_vip_v1_1_3
vmap processing_system7_vip_v1_0_5 activehdl/processing_system7_vip_v1_0_5

vlog -work xilinx_vip  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"L:/Xilinx_201802/Vivado/2018.2/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
"L:/Xilinx_201802/Vivado/2018.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93 \
"L:/Xilinx_201802/Vivado/2018.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/sc_util_v1_0_vl_rfs.sv" \

vlog -work axi_protocol_checker_v2_0_3  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../../net_test.srcs/sources_1/bd/design_1/ipshared/03a9/hdl/axi_protocol_checker_v2_0_vl_rfs.sv" \

vlog -work axi_vip_v1_1_3  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../../net_test.srcs/sources_1/bd/design_1/ipshared/b9a8/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_5  -sv2k12 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/5bb9/hdl/verilog" "+incdir+../../../../net_test.srcs/sources_1/bd/design_1/ipshared/70fd/hdl" "+incdir+L:/Xilinx_201802/Vivado/2018.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
"../../../bd/design_1/sim/design_1.v" \

vlog -work xil_defaultlib \
"glbl.v"

