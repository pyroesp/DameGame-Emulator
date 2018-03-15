#ifndef _SPECIAL_REGISTER_H
#define _SPECIAL_REGISTER_H

union Special_Register{
	uint8_t reg[0x100]; /* point to FF00 in the memory */
	struct{
		union{
			uint8_t P1; // Reading joypad FF00
			struct{
				uint8_t P10 : 1;
				uint8_t P11 : 1;
				uint8_t P12 : 1;
				uint8_t P13 : 1;
				uint8_t P14 : 1;
				uint8_t P15 : 1;
				uint8_t unused : 2;
			}P1_bits;
		};
		uint8_t SB; // Serial Transfer Data FF01
		union{
			uint8_t SC; // SIO Control FF02
			struct{
				uint8_t clock : 1;
				uint8_t unused : 6;
				uint8_t transfer_flag : 1;
			}SC_bits;
		};
		uint8_t unused0; // FF03
		uint8_t DIV; // Divider Register FF04
		uint8_t TIMA; // Timer Counter FF05
		uint8_t TMA; // Timer Modulo FF06
		union{
			uint8_t TAC; // Timer Control FF07
			struct{
				uint8_t clock_select : 2;
				uint8_t timer_stop : 1;
				uint8_t unused : 5;
			}TAC_bits;
		};
		uint8_t unused1[0x07]; // FF08 - FF0E
		union{
			uint8_t IF; // Interrupt flag FF0F
			struct{
				uint8_t v_blank : 1;
				uint8_t lcdc : 1;
				uint8_t timer_overflow : 1;
				uint8_t serial_transfer_complete : 1;
				uint8_t falling_edge_P1 : 1;
				uint8_t unused : 3;
			}IF_bits;
		};
		union{
			uint8_t NR_10; // FF10
			struct{
				uint8_t sweep_shift : 3;
				uint8_t sweep_inc_dec : 1;
				uint8_t sweep_time : 3;
				uint8_t unused : 1;
			}NR_10_bits;
		};
		union{
			uint8_t NR_11; // FF11
			struct{
				uint8_t sound_len : 6;
				uint8_t wave_patern_duty : 2;
			}NR_11_bits;
		};
		union{
			uint8_t NR_12; // FF12
			struct{
				uint8_t envelope_sweep : 3;
				uint8_t envelope : 1;
				uint8_t envelope_volume : 4;
			}NR_12_bits;
		};
        struct{
            union{
                uint8_t NR_13; // FF13
                uint8_t freq_lo_1;
            };
            union{
                uint8_t NR_14; // FF14
                struct{
                    uint8_t freq_hi : 3;
                    uint8_t unused : 3;
                    uint8_t sound_mode : 1; // consecutive or counter mode
                    uint8_t sound_restart : 1;
                }NR_14_bits;
            };
        };
		uint8_t unused2; // FF15
		union{
			uint8_t NR_21; // FF16
			struct{
				uint8_t sound_len : 6;
				uint8_t wave_pattern_duty : 2;
			}NR_21_bits;
		};
		union{
			uint8_t NR_22; // FF17
			struct{
				uint8_t envelope_sweep : 3;
				uint8_t envelope : 1;
				uint8_t envelope_volume : 4;
			}NR_22_bits;
		};
        struct{
            union{
                uint8_t NR_23; // FF18
                uint8_t freq_lo_2;
            };
            union{
                uint8_t NR_24; // FF19
                struct{
                    uint8_t freq_hi : 3;
                    uint8_t unused : 3;
                    uint8_t sound_mode : 1; // consecutive or counter mode
                    uint8_t sound_restart : 1;
                }NR_24_bits;
            };
        };
		union{
			uint8_t NR_30; // FF1A
			struct{
				uint8_t unused : 7;
				uint8_t sound_output : 1; // off / on
			}NR_30_bits;
		};
		union{
			uint8_t NR_31; // sound length FF1B
			uint8_t sound_len_3;
		};
		union{
			uint8_t NR_32; // FF1C
			struct{
				uint8_t unused0 : 5;
				uint8_t select_output : 2;
				uint8_t unused1 : 1;
			}NR_32_bits;
		};
        struct{
            union{
                uint8_t NR_33; // FF1D
                uint8_t freq_lo_3;
            };
            union{
                uint8_t NR_34; // FF1E
                struct{
                    uint8_t freq_hi : 3;
                    uint8_t unused : 3;
                    uint8_t sound_mode : 1;
                    uint8_t sound_restart : 1;
                }NR_34_bits;
            };
        };
		uint8_t unused3; // FF1F
		union{
			uint8_t NR_41; // FF20
			struct{
				uint8_t sound_len : 6;
				uint8_t unused : 2;
			}NR_41_bits;
		};
		union{
			uint8_t NR_42; // FF21
			struct{
				uint8_t envelope_sweep : 3;
				uint8_t envelope : 1;
				uint8_t envelope_volume : 4;
			}NR_42_bits;
		};
		union{
			uint8_t NR_43; // FF22
			struct{
				uint8_t div_ratio : 3;
				uint8_t poly_cnt_step : 1;
				uint8_t shift_clock_freq : 4;
			}NR_43_bits;
		};
		union{
			uint8_t NR_44; // FF23
            struct{
                uint8_t unused : 6;
                uint8_t sound_mode : 1; // consecutive or counter mode
            	uint8_t sound_restart : 1;
            }NR_44_bits;
        };
        union{
			uint8_t NR_50; // FF24
			struct{
				uint8_t S01_volume : 3;
				uint8_t S01_output : 1; // on/off
				uint8_t S02_volume : 3;
				uint8_t S02_output : 1; // on/off
			}NR_50_bits;
		};
		uint8_t NR_51; // FF25
		uint8_t NR_52; // FF26

		uint8_t unused4[0x3]; // FF27-FF29

		uint8_t wave_pattern[0x10]; // FF30-FF3F

		uint8_t LCDC; // FF40
		uint8_t STAT; // LCDC status FF41
		uint8_t SCY; // FF42
		uint8_t SCX; // FF43
		uint8_t LY; // FF44
		uint8_t LYC; // FF45
		uint8_t DMA; // FF46
		uint8_t BGP; // FF47
		uint8_t OBP0; // FF48
		uint8_t OBP1; // FF49
		uint8_t WY; // FF4A
		uint8_t WX; // FF4B
		uint8_t unused5[0xB4]; // FF4C - FFFE
		uint8_t IE; // FFFF
    };
};

#endif
