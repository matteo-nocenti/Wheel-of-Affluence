#include "wheel.hpp"

void Wheel::load() {


	_roll = {
		{ "Valkiries Atk Lunga",{ 1500, 750 } },
		{ "Valkiries Atk Mischia",{ 1500, 1500 } },
		{ "Valkiries Def Lunga",{ 1500, 2250 } },
		{ "Valkiries Def Mischia",{ 1500, 3000 } },

		{ "Ticket",{ 1   , 4500 } },

		{ "Glory Banner 10%",{ 1000   , 4846 } },
		{ "Glory Banner 11%",{ 1000   , 5046 } },

		{ "Nomad Tablet 10%",{ 1000   , 5392 } },
		{ "Nomad Tablet 11%",{ 1000   , 5592 } },

		{ "Samurai Token 10%",{ 1000   , 5938 } },
		{ "Samurai Token 11%",{ 1000   , 6138 } },

		{ "Berimond Gallantry 5%",{ 1000   , 6484 } },
		{ "Berimond Gallantry 6%",{ 1000   , 6684 } },

		{ "Rage Banner",{ 1000   , 7030 } },
		{ "Khan Arrow",{ 1000   , 7376 } },

		{ "Khan Chest",{ 1000   , 7468 } },
		{ "Khan Moat",{ 1000   , 7560 } },

		{ "Equipment",{ 1   , 8560 } },
		{ "Jackpot",{ 1   , 10000 } }

	};


	_jackpot[1] = {
		{ " Sceat ",						{ 20, 444 } },
		{ " Upgrade token ",				{ 32, 1111 } },
		{ " Construction token ",			{ 16, 1444 } },
		{ " Rubies ",						{ 50000, 1555 } },
		{ " Mystery box | rarity 1 ",		{ 2, 1888 } },
		{ " Mystery box | rarity 2 ",		{ 1, 2221 } },
		{ " Mystery box | rarity 3 ",		{ 1, 2554 } },
		{ " Mystery box | rarity 4 ",		{ 1, 2887 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[2] = { 
		{ " Sceat ",						{ 30, 444 } },
		{ " Upgrade token ",				{ 64, 1111 } },
		{ " Construction token ",			{ 32, 1444 } },
		{ " Rubies ",						{ 100000, 1555 } },
		{ " Mystery box | rarity 1 ",		{ 3, 1888 } },
		{ " Mystery box | rarity 2 ",		{ 2, 2221 } },
		{ " Mystery box | rarity 3 ",		{ 2, 2554 } },
		{ " Mystery box | rarity 4 ",		{ 1, 2887 } },
		{ " Other ",						{ 1, 10000 } } 
	};
	_jackpot[3] = { 
		{ " Sceat ",						{ 40, 444 } },
		{ " Upgrade token ",				{ 128, 1111 } },
		{ " Construction token ",			{ 64, 1444 } },
		{ " Rubies ",						{ 150000, 1555 } },
		{ " Mystery box | rarity 1 ",		{ 4, 1888 } },
		{ " Mystery box | rarity 2 ",		{ 3, 2221 } },
		{ " Mystery box | rarity 3 ",		{ 3, 2554 } },
		{ " Mystery box | rarity 4 ",		{ 2, 2887 } },
		{ " Other ",						{ 1, 10000 } } 
	};
	_jackpot[4] = {
		{ " Sceat ",						{ 50, 444 } },
		{ " Upgrade token ",				{ 192, 1111 } },
		{ " Construction token ",			{ 96, 1444 } },
		{ " Rubies ",						{ 300000, 1555 } },
		{ " Mystery box | rarity 2 ",		{ 4, 1888 } },
		{ " Mystery box | rarity 3 ",		{ 4, 2221 } },
		{ " Mystery box | rarity 4 ",		{ 2, 2554 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[5] = {
		{ " Sceat ",						{ 60, 444 } },
		{ " Upgrade token ",				{ 256, 1111 } },
		{ " Construction token ",			{ 128, 1444 } },
		{ " Rubies ",						{ 400000, 1555 } },
		{ " Mystery box | rarity 2 ",		{ 5, 1888 } },
		{ " Mystery box | rarity 3 ",		{ 5, 2221 } },
		{ " Mystery box | rarity 4 ",		{ 3, 2554 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[6] = {
		{ " Sceat ",						{ 70, 444 } },
		{ " Upgrade token ",				{ 320, 1111 } },
		{ " Construction token ",			{ 160, 1444 } },
		{ " Rubies ",						{ 500000, 1555 } },
		{ " Mystery box | rarity 3 ",		{ 7, 1888 } },
		{ " Mystery box | rarity 4 ",		{ 5, 2221 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[7] = {
		{ " Sceat ",						{ 80, 444 } },
		{ " Upgrade token ",				{ 384, 1111 } },
		{ " Construction token ",			{ 192, 1444 } },
		{ " Rubies ",						{ 600000, 1555 } },
		{ " Mystery box | rarity 3 ",		{ 8, 1888 } },
		{ " Mystery box | rarity 4 ",		{ 6, 2221 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[8] = {
		{ " Sceat ",						{ 90, 444 } },
		{ " Upgrade token ",				{ 512, 1111 } },
		{ " Construction token ",			{ 256, 1444 } },
		{ " Rubies ",						{ 800000, 1555 } },
		{ " Mystery box | rarity 3 ",		{ 10, 1888 } },
		{ " Mystery box | rarity 4 ",		{ 8, 2221 } },
		{ " Other ",						{ 1, 10000 } }
	};
	_jackpot[9] = {
		{ " Unit wall sticker +510 ",		{ 1, 343 } },
		{ " Food production sticker +403 ", { 1, 1010 } },
		{ " Sceat ",						{ 100, 1677 } },
		{ " Upgrade token ",				{ 640, 2344 } },
		{ " Construction token ",			{ 320, 2687 } },
		{ " Rubies ",						{ 1000000, 2715 } },
		{ " Mystery box | rarity 4 ",		{ 5, 3058 } },
		{ " Other ",						{ 1, 10000 } }
	};
}