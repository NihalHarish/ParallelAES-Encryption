all : Serial_Encrypt Serial_Decrypt Parallel_Encrypt Parallel_Decrypt

Serial_Encrypt : Code/Encryption/AES_Encrypt_File_Read.cpp
				g++ Code/Encryption/AES_Encrypt_File_Read.cpp -o Serial_Encrypt
Serial_Decrypt : Code/Encryption/AES_Encrypt_File_Read.cpp
				g++ Code/Decryption/AES_Decrypt_File.cpp -o Serial_Decrypt
Parallel_Encrypt : Code/Encryption/AES_Encrypt_File_Read.cpp
				g++ Code/Encryption/AES_Encrypt_File_Read.cpp -o Parallel_Encrypt -fopenmp
Parallel_Decrypt : Code/Encryption/AES_Encrypt_File_Read.cpp
				g++ Code/Decryption/AES_Decrypt_File.cpp -o Parallel_Decrypt -fopenmp
clean : 
		rm Serial_Decrypt Serial_Encrypt Parallel_Decrypt Parallel_Encrypt
