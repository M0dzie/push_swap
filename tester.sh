# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 10:44:37 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/27 17:11:34 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

BLUE='\033[0;34m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NOCOLOR='\033[0m'

echo -e "${BLUE}ERROR CASE${NOCOLOR}"
echo ""
echo -e "${YELLOW}testing w/o arg :${NOCOLOR}"
./push_swap
echo -e "${GREEN}should display nothing${NOCOLOR}"
echo ""
echo -e "${YELLOW}testing w/o arg in str :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap ""
echo ""
echo -e "${YELLOW}testing different types of arg :${NOCOLOR}"
echo -e "${GREEN}should display some operations :${NOCOLOR}"
sleep .1s && ./push_swap 45 "21 78" 12
echo ""
echo -e "${YELLOW}testing huge number :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap 999999999999999999999999
echo ""
echo -e "${YELLOW}testing INT_MAX :${NOCOLOR}"
echo -e "${GREEN}should display nothing${NOCOLOR}"
sleep .1s && ./push_swap 2147483647
echo ""
echo -e "${YELLOW}testing INT_MIN :${NOCOLOR}"
echo -e "${GREEN}should display nothing${NOCOLOR}"
sleep .1s && ./push_swap -2147483648
echo ""
echo -e "${YELLOW}testing INT_MAX error :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap 2147483648
echo ""
echo -e "${YELLOW}testing INT_MIN error :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap -2147483649
echo ""
echo -e "${YELLOW}testing multiple '-' :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap -50 - 
echo ""
echo -e "${YELLOW}testing multiple '+' :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap +50 + 
echo ""
echo -e "${YELLOW}testing multiple '+' and '-' :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap +50 +- 
echo ""
echo -e "${YELLOW}testing '-' between 2 numbers :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap 1 2-3 4
echo ""
echo -e "${YELLOW}testing '-' between 2 numbers and quotes :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap "1 2-3 4"
echo ""
echo -e "${YELLOW}testing similar numbers :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep 1s && ./push_swap 462002 -184593 105992 276926 -135201 203397 62267 -424691 66222 496992 -152747 247813 12504 476257 -139282 60549 -428661 461759 4834 372674 378527 476325 -465396 -421855 497967 6729 286538 -453548 465739 -229456 -136705 -367110 -74380 149040 33019 -49628 396353 296101 292826 -283676 456379 474605 100541 -425769 -425765 -413517 -429565 -328104 -196343 -209065 488548 455846 -152559 247348 -66537 -497976 -466434 -341009 461109 366601 -405714 -412398 8944 -268725 464684 -293455 -107665 -153986 -106618 -425346 -85329 -351543 -235741 130556 -295949 -368930 -411783 -402382 -229456 212726 -398959 88737 -357228 332510 -66060 -363977 -53996 -374185 40017 467463 -248923 -407782 332704 -53276 347992 -147369 -468192 13062 -397708 419796
echo ""
echo -e "${YELLOW}testing alphabetic arg :${NOCOLOR}"
echo -e "${GREEN}should display 'Error' in stderr :${NOCOLOR}"
sleep .1s && ./push_swap 1 2 3 5 4 four 8 7
echo ""
echo -e "${YELLOW}testing leaks :${NOCOLOR}"
echo -e "${GREEN}1 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap -367110 -74380 149040 33019 -49628 396353 296101 292826 -283676 456379 474605 100541 -425769 -425765 -413517 -429565 -328104 -196343 -209065 488548 455846 -152559 247348 -66537 -497976 -466434 -341009 461109 366601 -405714 | grep "leaks for"
echo -e "${GREEN}2 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap 1 2 3 | grep "leaks for"
echo -e "${GREEN}3 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap | grep "leaks for"
echo -e "${GREEN}4 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap 3 1 2 | grep "leaks for"
echo -e "${GREEN}5 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap 3 1 2 4 5 | grep "leaks for"
echo -e "${GREEN}6 :${NOCOLOR}"
sleep .1s && leaks -atExit -- ./push_swap 443116 237816 153036 340243 -474736 -233592 43837 -392922 -311057 312002 198848 230348 368753 -441072 161730 31694 423731 -43939 -75643 455830 29191 -447832 462266 -334712 -318223 -381999 -347034 -116682 204481 -22874 8847 283647 -84278 -477896 474221 -198849 -182107 -337039 259549 -81183 84610 -148597 162595 41193 -365729 -271088 -240203 -467879 300880 -353247 345214 -148676 -420911 253026 -87396 -380816 104724 261873 11446 129743 434030 -462125 -51484 217668 -457991 -264067 -200108 339879 -268741 -48582 461130 337192 152828 -100689 430386 224294 -154730 -448696 -87389 -247364 369559 143463 -412267 -439120 415763 28062 -380861 276430 -110591 -418644 -393542 -153905 -109315 250131 -248135 43465 -84629 -288881 50370 14930 359299 -422458 -448671 291349 -325501 -173979 -178528 -215426 271297 293394 -239371 -52563 482749 -213740 -488913 122883 -84661 -495349 -224258 -267368 28351 255833 151357 -127160 115663 -236792 232989 -207247 -121767 -292746 -255342 -219612 -373845 471044 -224620 -278259 -405028 -120094 9580 -125339 -86911 65089 85747 313533 -150474 394365 30125 -4378 388857 -425771 175010 404747 -211153 -340196 -264099 -352652 234141 -327287 138778 311745 24225 413197 -225214 117099 -445992 -128552 -180232 -31150 -455681 244778 -3662 29709 -305753 -450567 -304227 -87692 -399178 -382851 304537 -254339 -492771 325667 -476159 430625 378505 -24468 -65736 293661 382563 -406187 14387 134391 373636 483479 -89034 67039 478784 -448467 79848 -211242 -109984 143446 224859 -14926 -437412 -105729 251843 16199 90456 -411988 1294 -25012 -43454 317155 -336425 -105949 133692 136014 -229683 -100800 -94791 -26846 206283 54141 382786 413824 140242 -441160 278557 -269153 326890 -118404 -327951 -352673 -249927 -413186 466990 239257 322568 -209640 137022 -2418 334477 417339 216431 -3491 -465379 -49510 111153 238616 202804 137533 -493155 392092 144701 -127438 -403802 -82319 -10657 72689 -285923 -301259 360574 -303324 -73403 -278165 -161444 1961 300141 -421392 149054 245851 302399 388868 319814 218659 174035 -286687 336497 239152 358297 -87616 -195091 50790 -495951 401014 269941 200729 -182166 299606 -274012 387232 -225295 -147784 328208 163568 413857 448065 379583 -389318 94354 302207 -488271 -273962 101797 -476882 -207702 -410625 -380321 -159225 400898 156464 -68983 412634 405659 195825 249498 460838 -55570 358530 -292076 -84958 -109732 -447300 273798 405623 25953 -252658 -490822 -190522 326115 479392 342290 425505 -360794 285234 191606 52974 200750 156856 449813 -461171 267696 101903 -8657 104899 252603 -22690 -269591 25229 213216 351680 183288 -14458 -498542 -481582 144426 23700 191916 -110773 -407485 416842 -216614 -144889 451136 -115708 -128715 135481 311441 247593 -79771 147898 -383886 -237384 49284 110910 -112960 -133145 -395882 -491260 -181992 321614 -161136 -206578 -8183 -476216 -196345 48420 -404403 296106 -493856 323743 -84883 -332369 251235 420183 414098 308283 287828 67024 -25797 -404078 -201061 120291 -197823 -294236 291796 358144 -7859 -484271 414269 -478791 139477 -491208 19435 -64266 149759 130010 -7123 87945 -434192 -63499 190500 274950 381180 459158 -125003 164789 307655 -292620 74209 214186 327723 -1342 87492 95322 -368100 -440029 -84430 323510 251653 456529 -240834 -360526 396143 -254151 15843 -191694 380924 205204 -491406 262865 427928 -415399 -386325 155925 -315918 114086 339007 -80754 104906 362470 135070 -473218 55389 371915 -300505 87194 -285002 -208891 -472049 -465285 413667 109798 -361038 409327 351257 -393931 -78480 -483107 -10223 71350 346966 33826 -440175 128319 -412640 -461167 -323683 -245860 -179507 -471970 35648 132133 241733 -236647 -171880 287173 -347475 162360 | grep "leaks for"

echo ""
echo ""
echo -e "${BLUE}BASIC SORTING${NOCOLOR}"
echo ""
echo -e "${YELLOW}testing already sort :${NOCOLOR}"
echo -e "${GREEN}should display nothing${NOCOLOR}"
sleep .1s && ./push_swap 1 2 3 4
echo ""
echo -e "${YELLOW}testing non sort :${NOCOLOR}"
echo -e "${GREEN}should display some operations :${NOCOLOR}"
sleep .1s && ./push_swap 2 1

echo ""
echo ""
echo -e "${BLUE}SORTING SIZE 3${NOCOLOR}"
echo ""
echo -e "${YELLOW}3 operations max :${NOCOLOR}"
echo ""
sleep .1s && ./push_swap 1 3 2 | wc -l
sleep .1s && ./push_swap 2 1 3 | wc -l
sleep .1s && ./push_swap 2 3 1 | wc -l
sleep .1s && ./push_swap 3 1 2 | wc -l
sleep .1s && ./push_swap 3 2 1 | wc -l

echo ""
echo ""
echo -e "${BLUE}SORTING SIZE 5${NOCOLOR}"
echo ""
echo -e "${YELLOW}12 operations max :${NOCOLOR}"
echo ""
sleep .1s && ./push_swap -2147483648 -2147483647 0 9487 2147483647 | wc -l
sleep .1s && ./push_swap -2147483648 0 9487 -2147483647 2147483647 | wc -l
sleep .1s && ./push_swap 0 9487 -2147483647 -2147483648 2147483647 | wc -l
sleep .1s && ./push_swap 9487 0 -2147483648 -2147483647 2147483647 | wc -l
sleep .1s && ./push_swap 9487 0 -2147483647 -2147483648 2147483647 | wc -l
sleep .1s && ./push_swap 2147483647 9487 -2147483647 -2147483648 0 | wc -l
sleep .1s && ./push_swap -2147483647 -2147483648 0 2147483647 9487 | wc -l
sleep .1s && ./push_swap -2147483648 9487 0 -2147483647 2147483647 | wc -l
sleep .1s && ./push_swap 9487 2147483647 0 -2147483647 -2147483648 | wc -l
sleep .1s && ./push_swap 2147483647 -2147483647 0 -2147483648 9487 | wc -l

echo ""
echo ""
echo -e "${BLUE}SORTING SIZE 100${NOCOLOR}"
echo ""
echo -e "${YELLOW}less than 700 : 5${NOCOLOR}"
echo -e "${YELLOW}less than 900 : 4${NOCOLOR}"
echo -e "${YELLOW}less than 1 100 : 3${NOCOLOR}"
echo -e "${YELLOW}less than 1 300 : 2${NOCOLOR}"
echo -e "${YELLOW}less than 1 500 : 1${NOCOLOR}"
echo ""
sleep .1s && ./push_swap 462002 -184593 105992 276926 -135201 203397 62267 -424691 66222 496992 -152747 247813 12504 476257 -139282 60549 -428661 461759 4834 372674 378527 476325 -465396 -421855 497967 6729 286538 -453548 465739 -229456 -136705 -367110 -74380 149040 33019 -49628 396353 296101 292826 -283676 456379 474605 100541 -425769 -425765 -413517 -429565 -328104 -196343 -209065 488548 455846 -152559 247348 -66537 -497976 -466434 -341009 461109 366601 -405714 -412398 8944 -268725 464684 -293455 -107665 -153986 -106618 -425346 -85329 -351543 -235741 130556 -295949 -368930 -411783 -402382 488159 212726 -398959 88737 -357228 332510 -66060 -363977 -53996 -374185 40017 467463 -248923 -407782 332704 -53276 347992 -147369 -468192 13062 -397708 419796 | wc -l
sleep .1s && ./push_swap 380389 -51469 143361 -69515 -235437 310875 327397 262674 259280 -356206 185002 -435371 -55343 -379683 -333721 289470 186204 182270 204544 -65142 139706 115822 -232434 -463619 108643 -335207 67390 -445235 -255187 325867 -226417 12603 237088 -160417 395673 -250126 -149195 257815 -70360 254512 -108645 -148669 112213 -486870 -14595 -235116 12205 440108 -17857 -418739 -12413 91940 30574 87373 -78204 194004 -441386 415873 -9146 443896 255236 485290 37691 74804 -23896 412197 -317901 64166 496788 498578 -292195 -256546 -463387 67529 -271396 299985 359371 -318508 108831 218917 394271 224834 -382878 -309153 -437827 -246815 -185397 55540 -315236 -177280 63882 467900 -39327 -248637 339865 379054 -212964 -240331 -87022 -353855 | wc -l
sleep .1s && ./push_swap 417043 -28569 -278523 -343320 -127767 -407354 180599 383512 -473102 -348341 459839 276391 134768 -289955 -265616 183057 305157 -194493 -13153 269706 -342544 -160490 142578 403959 -307831 -41102 221082 177271 251242 240878 -308771 -21144 -247003 -190401 -298898 -383557 -340675 -33374 292319 412615 -249601 465589 164385 106304 -106826 -73659 -35082 74430 492360 111920 156797 -3536 -215764 -1486 225111 181964 -96837 305556 -4071 -439374 -179521 -405088 -441105 -321724 -26929 293565 459087 -29811 -337493 280171 172322 -306987 4977 104828 -180685 -169953 -272831 -187393 -224164 484423 364996 465975 -481148 -46170 451150 104587 382195 -225633 -135902 -468400 360077 -248962 490970 -406747 246844 260633 -332234 219584 -279863 -395989 | wc -l

echo ""
echo ""
echo -e "${BLUE}SORTING SIZE 500${NOCOLOR}"
echo ""
echo -e "${YELLOW}less than 5 500 : 5${NOCOLOR}"
echo -e "${YELLOW}less than 7 000 : 4${NOCOLOR}"
echo -e "${YELLOW}less than 8 500 : 3${NOCOLOR}"
echo -e "${YELLOW}less than 10 000 : 2${NOCOLOR}"
echo -e "${YELLOW}less than 11 500 : 1${NOCOLOR}"
echo ""
sleep .1s && ./push_swap 443116 237816 153036 340243 -474736 -233592 43837 -392922 -311057 312002 198848 230348 368753 -441072 161730 31694 423731 -43939 -75643 455830 29191 -447832 462266 -334712 -318223 -381999 -347034 -116682 204481 -22874 8847 283647 -84278 -477896 474221 -198849 -182107 -337039 259549 -81183 84610 -148597 162595 41193 -365729 -271088 -240203 -467879 300880 -353247 345214 -148676 -420911 253026 -87396 -380816 104724 261873 11446 129743 434030 -462125 -51484 217668 -457991 -264067 -200108 339879 -268741 -48582 461130 337192 152828 -100689 430386 224294 -154730 -448696 -87389 -247364 369559 143463 -412267 -439120 415763 28062 -380861 276430 -110591 -418644 -393542 -153905 -109315 250131 -248135 43465 -84629 -288881 50370 14930 359299 -422458 -448671 291349 -325501 -173979 -178528 -215426 271297 293394 -239371 -52563 482749 -213740 -488913 122883 -84661 -495349 -224258 -267368 28351 255833 151357 -127160 115663 -236792 232989 -207247 -121767 -292746 -255342 -219612 -373845 471044 -224620 -278259 -405028 -120094 9580 -125339 -86911 65089 85747 313533 -150474 394365 30125 -4378 388857 -425771 175010 404747 -211153 -340196 -264099 -352652 234141 -327287 138778 311745 24225 413197 -225214 117099 -445992 -128552 -180232 -31150 -455681 244778 -3662 29709 -305753 -450567 -304227 -87692 -399178 -382851 304537 -254339 -492771 325667 -476159 430625 378505 -24468 -65736 293661 382563 -406187 14387 134391 373636 483479 -89034 67039 478784 -448467 79848 -211242 -109984 143446 224859 -14926 -437412 -105729 251843 16199 90456 -411988 1294 -25012 -43454 317155 -336425 -105949 133692 136014 -229683 -100800 -94791 -26846 206283 54141 382786 413824 140242 -441160 278557 -269153 326890 -118404 -327951 -352673 -249927 -413186 466990 239257 322568 -209640 137022 -2418 334477 417339 216431 -3491 -465379 -49510 111153 238616 202804 137533 -493155 392092 144701 -127438 -403802 -82319 -10657 72689 -285923 -301259 360574 -303324 -73403 -278165 -161444 1961 300141 -421392 149054 245851 302399 388868 319814 218659 174035 -286687 336497 239152 358297 -87616 -195091 50790 -495951 401014 269941 200729 -182166 299606 -274012 387232 -225295 -147784 328208 163568 413857 448065 379583 -389318 94354 302207 -488271 -273962 101797 -476882 -207702 -410625 -380321 -159225 400898 156464 -68983 412634 405659 195825 249498 460838 -55570 358530 -292076 -84958 -109732 -447300 273798 405623 25953 -252658 -490822 -190522 326115 479392 342290 425505 -360794 285234 191606 52974 200750 156856 449813 -461171 267696 101903 -8657 104899 252603 -22690 -269591 25229 213216 351680 183288 -14458 -498542 -481582 144426 23700 191916 -110773 -407485 416842 -216614 -144889 451136 -115708 -128715 135481 311441 247593 -79771 147898 -383886 -237384 49284 110910 -112960 -133145 -395882 -491260 -181992 321614 -161136 -206578 -8183 -476216 -196345 48420 -404403 296106 -493856 323743 -84883 -332369 251235 420183 414098 308283 287828 67024 -25797 -404078 -201061 120291 -197823 -294236 291796 358144 -7859 -484271 414269 -478791 139477 -491208 19435 -64266 149759 130010 -7123 87945 -434192 -63499 190500 274950 381180 459158 -125003 164789 307655 -292620 74209 214186 327723 -1342 87492 95322 -368100 -440029 -84430 323510 251653 456529 -240834 -360526 396143 -254151 15843 -191694 380924 205204 -491406 262865 427928 -415399 -386325 155925 -315918 114086 339007 -80754 104906 362470 135070 -473218 55389 371915 -300505 87194 -285002 -208891 -472049 -465285 413667 109798 -361038 409327 351257 -393931 -78480 -483107 -10223 71350 346966 33826 -440175 128319 -412640 -461167 -323683 -245860 -179507 -471970 35648 132133 241733 -236647 -171880 287173 -347475 162360 | wc -l
sleep .1s && ./push_swap 139603 208915 419410 79928 -454898 424893 69669 -398693 -375631 60363 212239 -235155 -236205 496408 -431307 123573 -301488 -365546 -452749 220425 -329414 -240347 -455704 -166257 228671 -304958 -295207 -183480 193621 -388682 56763 -357752 -737 331400 -133096 67977 -25831 460612 -373089 -263833 -192829 -160134 470931 -41262 -185767 -480854 1495 72783 -131667 -110482 -301192 -158999 -123392 -434512 454629 398203 -437479 -368449 427621 434753 -476200 29177 428470 -202152 251937 74287 -69830 -451036 -113127 -451503 234488 209497 -192677 162037 -81256 497076 -126270 438271 233955 383787 212383 414075 119240 -317027 4027 -51112 -425560 -78446 -446029 125708 -294768 -336354 166705 -203002 -233120 -141585 -291596 -433256 68398 369439 215778 57793 -275757 190294 189818 -12340 -175066 252701 -403710 -192133 298156 116952 -499016 351670 160284 226919 -82809 212156 55850 88190 50689 -199002 -190377 -93577 487344 -101521 -260899 362350 25416 349019 473876 28838 -226574 -80369 378876 -293989 357043 -50285 100924 -431201 140922 226830 -324746 -169345 439252 356759 341572 225521 339781 -17376 -241669 287718 82822 -295401 168991 361901 190213 -289993 136980 -352348 234019 -11408 10894 -392156 105782 149239 338717 -40829 -453992 204991 389461 -341919 432008 -228149 186246 457794 149841 410997 -61531 376249 -252440 32841 333737 180004 479194 -212172 414544 424406 126069 397337 226310 309132 147206 172033 190923 497551 279826 175507 -80253 342470 52164 -422673 302923 -454838 316868 -175420 -186618 332550 -276802 404530 221160 -433328 -191439 -163966 -20335 -394689 195883 -436902 161129 -285945 -493775 -483439 434290 -302438 -13523 390904 -239377 360603 -263422 -344220 -376594 -111361 483067 -121003 490684 -101548 149307 456395 -200896 364992 -164624 -448183 -209279 34899 474646 485917 134836 373820 217 89617 -381682 -443014 265737 -112266 207118 -475860 40914 217675 -360090 330719 362963 -381288 -411343 -334839 67608 -318017 202286 -166515 377612 -282874 -22260 -114044 105932 236916 -65787 148870 339190 -82544 -283499 106319 -60452 -144450 304275 -177665 -172372 391176 -68772 337548 -324017 -165766 -464289 450400 -246371 -340871 170330 -320379 -171785 -162253 379941 184354 290729 -405324 -414531 -184452 9498 -239705 -473712 -213260 160806 242950 256418 376354 -161095 -294495 -479199 253247 407683 360352 -157168 -273087 -425676 -76227 29248 -332309 273390 -246629 219122 171127 -437559 133944 215018 45111 63222 362383 -204467 291821 92678 -106490 243873 471702 -376270 -401531 -204458 -94114 221688 -298523 -272532 198313 320154 -27984 215274 216101 -148932 333193 -499518 79808 39706 -411422 308997 431667 435611 -100851 205470 -228899 108348 105653 -160890 378105 32629 -339094 -200155 375387 236912 -109197 -198325 -27439 -213550 428361 82910 -212379 -99416 152704 -394796 -165142 326328 -300154 -45360 278175 358387 -124031 483920 55025 144738 38920 46895 -144123 220592 11234 -432609 315452 233070 -50197 259246 -140217 448662 -240103 -63446 -209149 197387 -267950 -61042 -449421 -497486 99867 -282844 -1376 58938 -43929 148753 -6505 422076 386539 154329 -476245 -25661 -252718 -134675 -401490 125883 70020 -65960 -16364 -146585 95258 -358868 -362871 -80213 -223414 62661 117440 486217 -213378 299125 66937 -474038 246173 -174347 -437093 211913 109871 62029 79597 -78635 308965 -78095 -263841 133202 436319 374094 -464218 32740 444059 202645 443253 270484 -226966 -306980 275040 -286989 340505 441620 -392222 -71832 353229 -169722 -115978 491826 -397274 -33242 118511 359945 -413734 261639 -129680 -299396 46195 176320 -304376 -262714 213278 245355 139116 -368980 -447434 64940 27016 150067 241543 -247324 -331477 | wc -l
sleep .1s && ./push_swap 123983 123763 -351777 -419206 -447641 197657 -478387 -484540 -292770 312284 309148 417372 88590 277165 74236 155991 -432812 -25446 169684 -401113 -366010 77756 -287399 -355668 -308192 251797 1892 -269072 24884 239049 245375 -372629 -118 -466872 -333640 381351 -363479 -419186 24491 22199 -270381 -308794 154309 -375824 -390278 -395345 -88726 -303391 -32318 499244 -19714 -315185 146656 324083 -329670 130940 433687 -343122 -39220 173816 -119951 -261422 -139791 220164 -27008 -91833 -57992 -297318 -493375 -444744 59181 -278881 309605 -276591 -449722 276617 408421 151278 482703 -123730 -301736 248748 211096 -357964 -367206 36881 191025 154441 192875 224844 424974 411481 -435305 373427 200845 383154 -193195 328040 -402726 116141 367189 -345707 -8552 -498325 324373 -114441 255742 145042 370974 452559 -363236 415279 -135698 -85294 -422952 -452402 -261472 79473 363711 484478 164493 -348328 132466 -460232 387527 89302 -385447 -331622 -220247 -259078 336381 -147633 385128 -434695 71566 190177 50090 431360 447102 -360194 285081 -68529 17107 -270123 275879 130194 322331 -357664 309440 170383 -260366 194406 45417 -456675 -486174 323353 -427377 -299459 297357 -453773 493528 -296349 446016 -155884 -270460 191296 459528 -71 353462 493401 -122450 56391 212597 -346177 495713 -102078 -139325 -405460 443932 -125262 -141028 -450666 314688 -445410 396455 484884 497955 -210729 468327 198652 -267201 -112855 74785 250000 -249473 -65454 384983 206478 -114638 -441888 158483 -497659 60420 -240170 365435 -404307 475612 380179 -206091 -262267 160120 -491089 -42615 -218102 339292 395958 -474594 258927 452792 145872 -209 164236 410616 437858 -401260 -276212 -298474 -422555 301667 94564 941 173936 373921 434014 -111072 -371625 -21082 -384216 301600 266570 106998 468891 -375211 -132992 -11117 -375125 12700 -30754 -102325 203083 -190795 385819 -256282 46720 397921 -373002 283624 -136981 444087 314336 -491272 -259605 -241613 -38963 15602 -473769 -289025 -381157 367669 -333827 -400546 252611 174608 163942 -241629 38391 189522 185532 -153992 144356 453183 -7915 185166 -416166 -44295 121050 -228434 460074 3073 -192472 -162842 350834 -457712 -291158 -299094 -120649 -222993 -269867 -413117 48179 -463325 335299 107590 250213 182857 -486239 -126530 377188 202539 123544 488508 -406255 -56207 -432892 -303275 368843 19840 -423785 420368 -168118 -97064 -139054 -176020 379068 -317799 -52994 313758 294836 490054 210526 -486840 -49291 4323 396911 -348622 384049 -37371 -410972 -404764 -324565 174786 263443 -197398 -445697 -39487 -313594 -260701 356976 45992 -57735 -224796 -446287 -95304 -285557 13521 -31246 -490565 225664 14830 -239642 -13018 -391731 260121 299085 -73676 195479 -252171 -432161 -98951 316222 285946 -301532 227628 -416575 38701 -298573 122631 -142032 284389 26602 489170 -290881 486569 -332941 -160232 -240394 -411174 79889 -360457 -377168 -321315 -444535 -344413 -61312 -499266 -175823 39854 270846 -366268 285368 -274431 201839 149497 192678 -469771 -305816 159753 -429877 97688 -334908 298883 -57301 39930 182003 321092 242684 -437591 -251482 -394672 414771 27674 -72315 -429350 -66726 348519 247902 -20659 15588 193262 -204119 -267760 294147 162850 442882 49437 -202856 -263967 450740 -390153 -18901 -306445 -222482 -273108 182305 141064 465324 333226 -263793 -319156 232562 -37996 -416660 33539 -137104 -121557 448695 473839 131961 50515 322617 -125200 385794 335634 -389813 391289 -10244 -289846 -468560 -385734 36316 -337713 388171 91852 320220 -82780 436640 -325306 21009 -98517 146012 -491518 178358 -63791 438359 469038 -152603 -112454 -324950 8816 -174286 -363825 96557 -33066 28441 473911 -253338 -322689 -377974 -386205 31272 | wc -l
