//==============================================================================================
//	FILENAME	:	TimeUtil.h
//	AUTHOR		:	Yuxiao Xiao
//	CREATION	:	8/24/01
//	Copyright (C) MicroStrategy, Inc. 2001
//==============================================================================================

#ifndef _TIMEUTIL_H
#define _TIMEUTIL_H

// days of each month for non-leap year
const short DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// days since Jan 1st to 1st of each month for non-leap year
const short DaysBeforeMonth[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// The following array maps year [0000, 1970] to year [1971, 2030] of the same pattern
// c runtime mktime() only works for year [1970, 2030]
// http://support.microsoft.com/kb/148790
// The mktime function fails for January 1, 1970 in several time zones that are ahead of Coordinated Universal Time 
const short DateAbove1970[] =
{
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0000 - 0009
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0010 - 0019
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 0020 - 0029
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 0030 - 0039
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0040 - 0049
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0050 - 0059
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0060 - 0069
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0070 - 0079
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0080 - 0089
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0090 - 0099
	1971, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0100 - 0109
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0110 - 0119
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0120 - 0129
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0130 - 0139
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 0140 - 0149
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 0150 - 0159
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0160 - 0169
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0170 - 0179
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0180 - 0189
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0190 - 0199
	1997, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0200 - 0209
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0210 - 0219
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0220 - 0229
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0230 - 0239
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 0240 - 0249
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 0250 - 0259
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0260 - 0269
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0270 - 0279
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0280 - 0289
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0290 - 0299
	1973, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0300 - 0309
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0310 - 0319
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0320 - 0329
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0330 - 0339
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0340 - 0349
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0350 - 0359
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 0360 - 0369
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 0370 - 0379
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0380 - 0389
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0390 - 0399
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0400 - 0409
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0410 - 0419
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 0420 - 0429
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 0430 - 0439
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0440 - 0449
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0450 - 0459
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0460 - 0469
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0470 - 0479
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0480 - 0489
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0490 - 0499
	1971, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0500 - 0509
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0510 - 0519
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0520 - 0529
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0530 - 0539
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 0540 - 0549
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 0550 - 0559
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0560 - 0569
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0570 - 0579
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0580 - 0589
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0590 - 0599
	1997, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0600 - 0609
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0610 - 0619
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0620 - 0629
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0630 - 0639
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 0640 - 0649
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 0650 - 0659
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0660 - 0669
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0670 - 0679
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0680 - 0689
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0690 - 0699
	1973, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0700 - 0709
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0710 - 0719
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0720 - 0729
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0730 - 0739
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0740 - 0749
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0750 - 0759
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 0760 - 0769
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 0770 - 0779
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0780 - 0789
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0790 - 0799
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0800 - 0809
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0810 - 0819
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 0820 - 0829
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 0830 - 0839
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 0840 - 0849
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 0850 - 0859
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0860 - 0869
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0870 - 0879
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0880 - 0889
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0890 - 0899
	1971, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 0900 - 0909
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 0910 - 0919
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 0920 - 0929
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 0930 - 0939
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 0940 - 0949
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 0950 - 0959
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 0960 - 0969
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 0970 - 0979
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 0980 - 0989
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 0990 - 0999
	1997, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1000 - 1009
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1010 - 1019
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1020 - 1029
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1030 - 1039
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 1040 - 1049
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 1050 - 1059
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1060 - 1069
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1070 - 1079
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1080 - 1089
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1090 - 1099
	1973, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1100 - 1109
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1110 - 1119
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1120 - 1129
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1130 - 1139
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1140 - 1149
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1150 - 1159
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 1160 - 1169
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 1170 - 1179
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1180 - 1189
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1190 - 1199
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1200 - 1209
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1210 - 1219
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 1220 - 1229
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 1230 - 1239
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1240 - 1249
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1250 - 1259
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1260 - 1269
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1270 - 1279
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1280 - 1289
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1290 - 1299
	1971, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1300 - 1309
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1310 - 1319
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1320 - 1329
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1330 - 1339
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 1340 - 1349
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 1350 - 1359
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1360 - 1369
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1370 - 1379
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1380 - 1389
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1390 - 1399
	1997, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1400 - 1409
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1410 - 1419
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1420 - 1429
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1430 - 1439
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 1440 - 1449
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 1450 - 1459
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1460 - 1469
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1470 - 1479
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1480 - 1489
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1490 - 1499
	1973, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1500 - 1509
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1510 - 1519
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1520 - 1529
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1530 - 1539
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1540 - 1549
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1550 - 1559
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 1560 - 1569
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 1570 - 1579
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1580 - 1589
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1590 - 1599
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1600 - 1609
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1610 - 1619
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 1620 - 1629
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 1630 - 1639
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1640 - 1649
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1650 - 1659
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1660 - 1669
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1670 - 1679
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1680 - 1689
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1690 - 1699
	1971, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1700 - 1709
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1710 - 1719
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1720 - 1729
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1730 - 1739
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, // 1740 - 1749
	1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, // 1750 - 1759
	1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1760 - 1769
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1770 - 1779
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1780 - 1789
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1790 - 1799
	1997, 1981, 1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, // 1800 - 1809
	1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, // 1810 - 1819
	1972, 1973, 1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, // 1820 - 1829
	1971, 1977, 2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, // 1830 - 1839
	1992, 1971, 1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, // 1840 - 1849
	1974, 1997, 1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, // 1850 - 1859
	2012, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1860 - 1869
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1870 - 1879
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1880 - 1889
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1890 - 1899
	1973, 1974, 1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, // 1900 - 1909
	1977, 1978, 1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, // 1910 - 1919
	1976, 1977, 1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, // 1920 - 1929
	1997, 1981, 1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, // 1930 - 1939
	1996, 1997, 1981, 1971, 1972, 1973, 1974, 1997, 1976, 1977, // 1940 - 1949
	1978, 1973, 1980, 1981, 1971, 1977, 2012, 1974, 1997, 1981, // 1950 - 1959
	1988, 1978, 1973, 1974, 1992, 1971, 1977, 1978, 1996, 1997,  // 1960 - 1969
	1981
};

#endif
