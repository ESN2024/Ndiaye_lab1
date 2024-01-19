library ieee;
use ieee.std_logic_1164.all;

entity lab1_vhd is port
(
	clk, rst : in std_logic;
	bouton : in  std_logic_vector(7 downto 0);
	led : out std_logic_vector(7 downto 0) 
);
end entity;

architecture arch of lab1_vhd is 

    component lab1 is
        port 
		  (
            clk_clk       : in  std_logic ; 
            reset_reset_n : in  std_logic ;
            led_export    : out std_logic_vector(7 downto 0);         
				bouton_export : in  std_logic_vector(7 downto 0)
        );
    end component lab1;
begin
    u0 : component lab1
        port map 
		  (
            clk_clk       => clk,       --   clk.clk
            reset_reset_n => rst, -- reset.reset_n
            led_export    => led,     --   led.export
				bouton_export => bouton  -- bouton.export
        );

end arch;