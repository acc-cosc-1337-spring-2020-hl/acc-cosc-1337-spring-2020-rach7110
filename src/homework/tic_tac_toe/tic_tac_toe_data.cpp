#include "tic_tac_toe_data.h"

void TicTacToeData::save_game(const vector<unique_ptr<TicTacToe> > &games)
{
    std::ofstream file_out(file_name, std::ios_base::trunc);
    
    for (auto &game : games)
    {
        string winner = game->get_winner();
        vector<string> pegs = game->get_pegs();
        
        // Write pegs to file.
        for (int i = 0; i < pegs.size(); ++i) {
            file_out << pegs[i];
        }
        
        file_out << winner;
		file_out << "\n";
    }
    
    file_out.close();
}

vector<unique_ptr<TicTacToe> > TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe> > boards;
    string line;
    vector<string> pegs;
    
    std::ifstream read_file(file_name);
    
    if (read_file.is_open())
    {
        while(getline(read_file, line))
        {
            // Pegs
            for(int i = 0; i < line.size() - 1; ++i)
            {
                pegs.push_back(string(1, line[i]));
            }
            
            // Winner
            string winner;
            winner = line.back();
			unique_ptr<TicTacToe> board;
            // Board size.
            if (pegs.size() == 9)
            {
                board = make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16)
            {
                board = make_unique<TicTacToe4>(pegs, winner);
            }
            
            boards.push_back(std::move(board));
            
			
        }
		read_file.close();

    }
    
	return boards;
}
