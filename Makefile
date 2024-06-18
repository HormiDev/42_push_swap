# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:43:11 by ide-dieg          #+#    #+#              #
#    Updated: 2024/06/18 23:41:53 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB_NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

SRC =	main.c \
		ft_push_swap_fb.c \
		ft_push_swap_v1.c \
		ft_push_swap_v2.c \
		ft_push_swap_v3.c \
		ft_push_swap_v4.c \
		fts_t_instructions.c \
		fts_t_instructions2.c \
		fts_t_push_swap.c \
		fts_t_stack.c \
		fts_t_stack2.c \
		fts_t_stack3.c \
		input.c \
		parsing.c \
		push_swap_utils.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		ft_atol.c \

all: libft push_swap

clean: libft_fclean

fclean: clean
	rm -f $(NAME)

libft:
	make -C 42_Libft

libft_fclean:
	make fclean -C 42_Libft

push_swap:
	$(CC) $(CFLAGS) $(SRC) 42_Libft/libft.a -o $(NAME)

re: fclean all

# TESTS

VERDE = \033[0;32m
ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m

ARGS1 = 2 2

ARGS2 = 1 2 3 2 1

ARGS3 = 1 2 3 -2147483649 2147483648

ARGS4 = 

ARGS5 = 42

ARGS6 = 2 3

ARGS7 = 0 1 2 3

ARGS8 = 0 1 2 3 4 5 6 7 8 9

ARGS9 = 0 2 3 5 6 7 9

ARGS10 = 2 1 0

ARGS11 = 0 2 1

ARGS12 = 2 0 1

ARGS13 = 1 5 2 4 3

ARGS14 = 2 4 1 3 5

ARGS15 = 802 -219 -43 786 -378

ARGS16 = 52 62 20 69 35 41 18 33 95 17 84 5 51 21 19 55 4 59 12 81 40 10 77 92 99 78 90 61 6 36 65 87 70 56 42 71 31 49 76 30 13 73 83 80 47 37 23 86 60 72 100 8 45 44 54 9 15 75 58 38 93 74 89 82 64 88 2 96 57 26 91 28 98 48 94 1 53 16 68 67 43 24 66 39 22 46 85 25 27 11 29 63 32 7 79 97 34 14 50 3

ARGS17 = 684 514 -479 -150 -337 849 425 239 802 -219 -43 786 -378 -451 67 -588 -392 417 -979 976 -199 316 -173 -132 -258 64 -515 709 -848 -803 -703 628 -315 -656 -913 775 -538 132 346 -595 -568 -161 -136 -261 -11 901 529 56 -860 -580 187 -49 -732 -577 710 848 -373 717 -386 22 -281 -293 957 -859 513 -167 563 -716 -670 -621 -389 -433 -291 896 413 860 221 -570 691 -345 719 -511 -977 -348 437 800 256 985 253 478 -351 -401 27 774 -771 381 73 35 391 -145

ARGS18 = 386 77 110 65 366 350 326 499 229 215 189 25 292 295 179 485 500 146 59 455 175 321 460 50 431 280 194 293 376 329 347 45 63 117 174 457 43 452 315 494 154 469 370 17 221 331 98 85 412 287 400 368 289 147 100 258 192 62 118 176 145 89 290 408 384 160 136 405 184 415 489 241 90 166 31 277 102 357 27 264 172 249 237 152 318 371 423 413 448 424 164 197 15 262 462 498 16 254 313 227 442 83 68 228 480 273 212 190 397 307 251 121 416 183 216 484 122 319 108 286 11 361 234 253 356 201 49 471 476 165 367 93 138 128 263 382 199 332 1 291 363 57 56 346 103 87 279 330 9 348 48 156 240 70 139 360 119 490 231 362 437 381 219 151 425 335 170 302 30 205 53 419 364 133 230 454 161 66 451 52 33 395 226 351 206 470 352 239 266 188 140 441 369 256 26 135 78 94 73 406 5 2 343 373 473 153 398 463 182 252 129 246 392 173 394 282 261 317 260 120 224 265 84 322 24 433 13 298 340 365 134 96 323 115 477 232 180 10 459 328 450 468 304 305 6 158 269 80 42 316 28 58 181 198 171 255 486 67 409 349 479 60 428 391 36 359 203 288 410 488 214 478 333 427 474 308 148 91 396 447 223 92 306 420 438 12 461 294 141 338 35 242 301 144 285 18 21 4 238 345 393 116 274 75 426 163 97 191 355 467 475 142 314 8 449 178 372 29 403 404 74 143 127 157 38 37 155 458 411 167 354 250 445 446 177 482 402 124 339 126 483 185 271 81 243 235 299 99 40 385 222 327 131 64 375 159 497 233 388 125 429 236 51 421 268 86 186 23 220 169 272 383 88 130 278 209 202 72 407 162 32 218 310 300 107 213 113 19 353 275 22 443 418 464 41 69 495 324 374 210 440 114 54 39 150 244 44 334 358 284 257 311 101 211 168 79 325 207 132 34 7 193 3 187 196 149 312 414 46 430 377 14 487 104 20 379 296 389 492 344 336 270 61 106 303 434 439 225 337 55 109 247 95 387 401 456 71 496 283 281 204 417 259 380 491 342 435 47 465 245 76 378 493 466 208 267 137 422 297 453 390 444 105 82 195 481 436 432 217 309 123 341 276 200 248 472 320 399 111 112

ARGS19 = 3523 4370 -431 -1049 -137 -4699 -2115 1542 1728 -4641 386 -3353 3531 -1674 -4364 -4260 -3118 2607 -3154 -2741 2327 4592 3475 -304 3335 1607 -1676 -3562 3848 1690 -4786 2362 -2508 1433 -1812 2272 3495 -3273 3687 1835 -3457 1242 -2623 -3080 1397 -2080 -1415 1473 1481 -2424 -95 -2289 3348 303 3124 1550 2530 4046 3646 -4361 -3598 -1455 -4278 1711 -1624 4425 -4942 -480 3996 2663 3146 3371 1487 -4128 1280 -3857 4498 4996 -3033 131 3070 -3687 -4293 566 1239 438 -1446 4469 -3076 -3450 1069 3312 4160 -3928 2825 1559 4402 -2121 1306 -2144 727 879 -1184 -2512 2675 1302 -1165 -2468 -4707 993 -704 412 -2255 -2905 4985 980 1962 40 -4785 2787 175 2896 -263 4138 -2986 4902 -826 589 -726 1800 -2010 3345 -4974 1246 -1914 -3337 -2483 -4062 -4238 -1323 -2650 3339 -1134 -4781 2583 -2848 4848 -454 -4660 -3197 -3499 4720 3398 -1015 3632 640 2193 -2399 -767 -3219 -2367 -927 4981 585 -1438 3831 -227 -3246 382 897 1846 -1461 -640 -1394 3079 -3771 -3474 -954 -1110 -1580 3889 1404 -3769 -4689 -4320 4519 4709 1282 2044 -3882 -3593 2973 -618 2971 669 -1099 4853 3234 -33 -2200 -2348 -3485 1149 -4666 1497 -939 2406 4759 960 697 2627 419 1437 2468 -2518 3982 207 -1266 2105 -345 1412 -937 -4026 1804 -4351 -1560 -940 5 -1423 -4620 2078 1003 1224 -532 3188 -4728 758 -2604 1523 -671 -2528 3250 1492 -853 1092 -121 -4279 -4889 3108 -3224 -1429 -2212 4721 -310 -1308 2955 -2601 1928 -3940 4183 2892 2179 2289 4679 3274 1256 -3568 -2358 3678 2742 2258 1857 -2904 -4224 1485 -3741 2244 4284 1583 -2300 -4583 -1778 1933 -3507 1758 3539 2176 -2325 -1480 4036 4187 -3659 -4569 -3441 -1583 -3775 4074 -521 635 2187 -3024 -2913 -2140 4031 -1591 3884 209 -1273 1185 1379 1862 -4022 -2552 398 1496 4548 -3036 -139 3968 -1086 3337 -4242 4322 1221 723 -1518 1854 -1418 -1081 1657 -4002 -4858 -4214 -3563 -3862 2513 1325 259 5000 136 -4910 -4797 2376 4014 -3121 417 1571 807 4124 3333 646 85 269 -3788 3329 2142 -2005 -4676 -1550 340 4624 -2052 -4151 -1475 4829 1959 -4967 -11 4785 3791 2570 -1329 -844 -2715 -4453 3762 -790 -4226 -1726 -63 3042 -1408 -1751 2253 2587 2938 3208 -4780 4336 3152 2789 1906 2835 -2003 3617 -4815 -725 -3628 -1232 4350 -1046 -2852 4209 4951 -4105 -1414 2988 2182 4885 -266 -3611 -2352 -1277 3388 -4362 1375 3854 4677 -798 -357 21 3161 4767 2326 -4013 937 -1388 -305 171 3861 142 -277 -4338 -3077 1191 -718 -4207 -2221 -419 -623 -1352 2800 -199 -3371 168 -3498 -2362 2131 1012 -2495 -4327 4727 4161 -3223 -422 1448 -3237 293 -2914 -3977 3863 -4756 -4091 -1420 4475 158 -239 -777 2766 3276 -3400 -371 3320 -683 4909 377 -2989 -2174 -2917 3988 4875 -3447 -3894 1337 -4421 -2823 2522 770 -2513 1301 -545 3004 -2721 -2030 -3319 -3456 339 4293 -3601 -3268

test: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17 test18 test19

test1:
	@echo "test 1"
	@echo parámetros no numéricos
	@if [ "$$(./$(NAME) $(ARGS1) 2>&1)" = "Error" ]; then \
		echo "Error $(VERDE)[OK]$(NC)\n"; \
	else \
		echo "Error $(ROJO)[KO]$(NC)\n"; \
	fi

test2:
	@echo "test 2"
	@echo "numérico duplicado"
	@if [ "$$(./$(NAME) $(ARGS2) 2>&1)" = "Error" ]; then \
		echo "Error $(VERDE)[OK]$(NC)\n"; \
	else \
		echo "Error $(ROJO)[KO]$(NC)\n"; \
	fi

test3:
	@echo "test 3"
	@echo "número fuera de rango"
	@if [ "$$(./$(NAME) $(ARGS3) 2>&1)" = "Error" ]; then \
		echo "Error $(VERDE)[OK]$(NC)\n"; \
	else \
		echo "Error $(ROJO)[KO]$(NC)\n"; \
	fi

test4:
	@echo "test 4"
	@echo "sin argumentos"
	@if [ "$$(./$(NAME) $(ARGS4))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test5:
	@echo "test 5"
	@echo "1 argumento"
	@if [ "$$(./$(NAME) $(ARGS5))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test6:
	@echo "test 6"
	@echo "2 argumentos ordenados"
	@if [ "$$(./$(NAME) $(ARGS6))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test7:
	@echo "test 7"
	@echo "4 argumentos ordenados"
	@if [ "$$(./$(NAME) $(ARGS7))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test8:
	@echo "test 8"
	@echo "10 argumentos ordenados"
	@if [ "$$(./$(NAME) $(ARGS8))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test9:
	@echo "test 9"
	@echo "7 argumentos aleatorios ordenados"
	@if [ "$$(./$(NAME) $(ARGS9))" = "" ]; then \
		echo "$(VERDE)[OK]$(NC)\n"; \
	else \
		echo "$(ROJO)[KO]$(NC)\n"; \
	fi

test10:
	@echo "test 10"
	@echo "3 argumentos ordenados al revés"
	@if [ "$$(./$(NAME) $(ARGS10) | ./checker_linux $(ARGS10))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS10) | wc -l) -le 3 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS10) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS10) | wc -l)]$(NC)\n"; \
	fi

test11:
	@echo "test 11"
	@echo "3 argumentos desordenados $(ARGS11)"
	@if [ "$$(./$(NAME) $(ARGS11) | ./checker_linux $(ARGS11))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS11) | wc -l) -le 3 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS11) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS11) | wc -l)]$(NC)\n"; \
	fi

test12:
	@echo "test 12"
	@echo "3 argumentos desordenados $(ARGS12)"
	@if [ "$$(./$(NAME) $(ARGS12) | ./checker_linux $(ARGS12))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS12) | wc -l) -le 3 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS12) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS12) | wc -l)]$(NC)\n"; \
	fi

test13:
	@echo "test 13"
	@echo "5 argumentos desordenados $(ARGS13)"
	@if [ "$$(./$(NAME) $(ARGS13) | ./checker_linux $(ARGS13))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS13) | wc -l) -le 12 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS13) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS13) | wc -l)]$(NC)\n"; \
	fi

test14:
	@echo "test 14"
	@echo "5 argumentos desordenados $(ARGS14)"
	@if [ "$$(./$(NAME) $(ARGS14) | ./checker_linux $(ARGS14))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS14) | wc -l) -le 12 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS14) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS14) | wc -l)]$(NC)\n"; \
	fi

test15:
	@echo "test 15"
	@echo "5 argumentos desordenados $(ARGS15)"
	@if [ "$$(./$(NAME) $(ARGS15) | ./checker_linux $(ARGS15))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS15) | wc -l) -le 12 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS15) | wc -l)]$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS15) | wc -l)]$(NC)\n"; \
	fi

test16:
	@echo "test 16"
	@echo "100 argumentos desordenados"
	@if [ "$$(./$(NAME) $(ARGS16) | ./checker_linux $(ARGS16))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS16) | wc -l) -le 700 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS16) | wc -l)] 5 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS16) | wc -l) -le 900 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS16) | wc -l)] 4 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS16) | wc -l) -le 1100 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS16) | wc -l)] 3 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS16) | wc -l) -le 1300 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS16) | wc -l)] 2 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS16) | wc -l) -le 1500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS16) | wc -l)] 1 PUNTOS$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS16) | wc -l)] 1 PUNTOS$(NC)\n"; \
	fi

test17:
	@echo "test 17"
	@echo "100 argumentos desordenados"
	@if [ "$$(./$(NAME) $(ARGS17) | ./checker_linux $(ARGS17))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS17) | wc -l) -le 700 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS17) | wc -l)] 5 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS17) | wc -l) -le 900 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS17) | wc -l)] 4 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS17) | wc -l) -le 1100 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS17) | wc -l)] 3 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS17) | wc -l) -le 1300 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS17) | wc -l)] 2 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS17) | wc -l) -le 1500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS17) | wc -l)] 1 PUNTOS$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS17) | wc -l)] 1 PUNTOS$(NC)\n"; \
	fi

test18:
	@echo "test 18"
	@echo "500 argumentos desordenados"
	@if [ "$$(./$(NAME) $(ARGS18) | ./checker_linux $(ARGS18))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS18) | wc -l) -le 5500 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS18) | wc -l)] 5 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS18) | wc -l) -le 7000 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS18) | wc -l)] 4 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS18) | wc -l) -le 8500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS18) | wc -l)] 3 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS18) | wc -l) -le 10000 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS18) | wc -l)] 2 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS18) | wc -l) -le 11500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS18) | wc -l)] 1 PUNTOS$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS18) | wc -l)] 1 PUNTOS$(NC)\n"; \
	fi

test19:
	@echo "test 19"
	@echo "500 argumentos desordenados"
	@if [ "$$(./$(NAME) $(ARGS19) | ./checker_linux $(ARGS19))" = "OK" ]; then \
		echo -n "chequer $(VERDE)[OK]$(NC)"; \
	else \
		echo -n "chequer $(ROJO)[KO]$(NC)"; \
	fi
	@echo -n " nº movimientos "
	@if [ $$(./$(NAME) $(ARGS19) | wc -l) -le 5500 ]; then \
		echo "$(VERDE)[$$(./$(NAME) $(ARGS19) | wc -l)] 5 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS19) | wc -l) -le 7000 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS19) | wc -l)] 4 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS19) | wc -l) -le 8500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS19) | wc -l)] 3 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS19) | wc -l) -le 10000 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS19) | wc -l)] 2 PUNTOS$(NC)\n"; \
	elif [ $$(./$(NAME) $(ARGS19) | wc -l) -le 11500 ]; then \
		echo "$(NARANJA)[$$(./$(NAME) $(ARGS19) | wc -l)] 1 PUNTOS$(NC)\n"; \
	else \
		echo "$(ROJO)[$$(./$(NAME) $(ARGS19) | wc -l)] 1 PUNTOS$(NC)\n"; \
	fi