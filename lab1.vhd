library ieee;
use ieee.std_logic_1164.all;

entity lab1_vhd is port
(
	clk, rst : in std_logic;
	bouton : in  std_logic;
	switch_export : in  std_logic_vector(3 downto 0);
	led : out std_logic_vector(7 downto 0) 
);
end entity;

architecture arch of lab1_vhd is 


    component lab1 is
        port (
            bouton_export : in  std_logic                    := 'X';             -- export
            clk_clk       : in  std_logic                    := 'X';             -- clk
            led_export    : out std_logic_vector(7 downto 0);                    -- export
            reset_reset_n : in  std_logic                    := 'X';             -- reset_n
            switch_export : in  std_logic_vector(3 downto 0) := (others => 'X')  -- export
        );
    end component lab1;
begin
    u0 : component lab1
        port map (
            bouton_export => bouton, -- bouton.export
            clk_clk       => clk,       --    clk.clk
            led_export    => led,    --    led.export
            reset_reset_n => rst, --  reset.reset_n
            switch_export => switch_export  -- switch.export
        );

end arch;