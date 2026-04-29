" Plug install
" vim-plug がない時に自動でインストール
let s:vim_plug_url='https://github.com/junegunn/vim-plug'
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
        \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

call plug#begin()

Plug 'preservim/nerdtree'
Plug 'tpope/vim-surround'
Plug 'dominikduda/vim_current_word'
Plug 'cohama/lexima.vim'
Plug 'easymotion/vim-easymotion'

Plug 'prabirshrestha/asyncomplete.vim'
Plug 'prabirshrestha/asyncomplete-lsp.vim'
Plug 'prabirshrestha/vim-lsp'
Plug 'mattn/vim-lsp-settings'
Plug 'mattn/vim-lsp-icons'

Plug 'hrsh7th/vim-vsnip'
Plug 'hrsh7th/vim-vsnip-integ'

" Leaderキー->spaceキー
let mapleader = "\<Space>"

" dominikduda用設定
let g:vim_current_word#highlight_current_word = 0

" easymotion用設定
map <Leader> <Plug>(easymotion-prefix)
let g:EasyMotion_do_mapping = 0 " Disable default mappings

" Jump to anywhere you want with minimal keystrokes, with just one key binding.
" `s{char}{label}`
" nmap s <Plug>(easymotion-overwin-f)
" or
" `s{char}{char}{label}`
" Need one more keystroke, but on average, it may be more comfortable.
nmap <Leader>s <Plug>(easymotion-overwin-f2)

" Turn on case insensitive feature
let g:EasyMotion_smartcase = 1

" JK motions: Line motions
map <Leader>j <Plug>(easymotion-j)
map <Leader>k <Plug>(easymotion-k)

map <Leader>w <Plug>(easymotion-w)
map <Leader>b <Plug>(easymotion-b)
map <Leader>e <Plug>(easymotion-e)

call plug#end()

" setting
"文字コードをUFT-8に設定
set fenc=utf-8
" バックアップファイルを作らない
set nobackup
" スワップファイルを作らない
set noswapfile
" 編集中のファイルが変更されたら自動で読み直す
set autoread
" バッファが編集中でもその他のファイルを開けるように
set hidden
" 入力中のコマンドをステータスに表示する
set showcmd
" jjでインサートから抜ける
inoremap <silent> jj <ESC>
" uuでインサートから抜ける
inoremap <silent> uu <ESC>
" ctrl+^で行末に行く
nnoremap <C-^> $
vnoremap <C-^> g$
" 大きく移動する
nnoremap J 10j
nnoremap K 10k
nnoremap L 10l
nnoremap H 10h
vnoremap J 10j
vnoremap K 10k
vnoremap L 10l
vnoremap H 10h
" 全選択
vnoremap , <ESC>ggVG
" 大文字化
nnoremap guu gUl;
" vimrcを更新
nnoremap <F5> :<C-u>source $MYVIMRC<CR>
" vimrcを開く
nnoremap <F4> :<C-u>tabedit $MYVIMRC<CR>


" 見た目系
" 行番号を表示
set number
" 現在の行を強調表示
set cursorline
" 行末の1文字先までカーソルを移動できるように
set virtualedit=onemore
" インデントはスマートインデント
set smartindent
" 括弧入力時の対応する括弧を表示
set showmatch
" ステータスラインを常に表示
set laststatus=2
" コマンドラインの補完
set wildmode=list:longest
" 折り返し時に表示行単位での移動できるようにする
nnoremap j gj
nnoremap k gk
" シンタックスハイライトの有効化
syntax enable
" 挿入モードのカーソル
let &t_SI = "\e[5 q"
" ノーマルモードのカーソル
let &t_EI = "\e[2 q"
" 置換モードのカーソル
let &t_SR = "\e[3 q"
" vim 起動時のカーソル
let &t_ti .= "\e[2 q"
" vim 終了時のカーソル
let &t_te .= "\e[3 q"


" Tab系
" 不可視文字を可視化(タブが「▸-」と表示される)
" set list listchars=tab:\▸\-
" Tab文字を半角スペースにする
" set expandtab
" 行頭以外のTab文字の表示幅（スペースいくつ分）
set tabstop=4
" 行頭でのTab文字の表示幅
set shiftwidth=4


" 検索系
" 検索文字列が小文字の場合は大文字小文字を区別なく検索する
set ignorecase
" 検索文字列に大文字が含まれている場合は区別して検索する
set smartcase
" 検索文字列入力時に順次対象文字列にヒットさせる
set incsearch
" 検索時に最後まで行ったら最初に戻る
set wrapscan
" 検索語をハイライト表示
set hlsearch
" ESC連打でハイライト解除
nmap <Esc><Esc> :nohlsearch<CR><Esc>
