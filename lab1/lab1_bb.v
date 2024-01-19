
module lab1 (
	bouton_export,
	clk_clk,
	led_export,
	reset_reset_n,
	switch_export);	

	input		bouton_export;
	input		clk_clk;
	output	[7:0]	led_export;
	input		reset_reset_n;
	input	[3:0]	switch_export;
endmodule
