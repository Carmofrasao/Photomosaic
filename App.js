
const { exec } = require('child_process');

const divs = document.querySelector('#conteiner');


// Caminho para o arquivo ELF que você deseja executar
const elfFilePath = './mosaico';

// Comando para executar o arquivo ELF
const command = `./${elfFilePath}`;

// Executa o comando
exec(command, (error, stdout, stderr) => {
  if (error) {
    console.error(`Erro ao executar o arquivo ELF: ${error}`);
    return;
  }
  console.log(`Saída padrão: ${stdout}`);
  console.error(`Saída de erro: ${stderr}`);
});
