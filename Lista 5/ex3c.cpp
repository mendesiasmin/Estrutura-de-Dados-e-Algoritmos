



encontrar_cartao(C)

	se o numero de cartoes em C == 1
		
		retorne este cartao

	se o numero de cartoes em C == 2

		retorne qualquer uma das cartas 
	

	Defina metade_esquerda como a metade esquerda de C

	Defina metade_direita como a metade direita de C

	
	cartao_esquerdo = encontrar_cartao(metade_esquerda)

	se cartao_esquero é não vazio

	para cada c cartao em C

		
		defina um contador

		compare c com cartao_esquerdo

		se c == cartao_esquerdo

			incremente o contador

		se o numero de cartoes obtidos for maior que a metade 

		returne cartao_esquerdo

	end for

	Se nao foi encontrado um cartao

		zere o contador

		cartao_direito = encontrar_cartao(metade_direita)

		se cartao_direito é não vazio

			para cada c cartao em C

				compare c com cartao_direito	

				se c == cartao_direito

					incremente o contador

		se o numero de cartoes obtidos for maior que a metade

		retorn cartao_direito
				
	end for			

end encontrar_cartao
