call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'benekastah/neomake'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-fugitive'
Plug 'Raimondi/delimitMate'
Plug 'lervag/vimtex'
"Color schemes
Plug 'flazz/vim-colorschemes'
call plug#end()

syntax enable		" enables syntax processing

"let $TERM='xterm'
"let $COLORTERM='xterm-256color'

colorscheme coldgreen 
set tabstop=3		" number of visual spaces per tab.
set smarttab		" tabs for indentation, spaces for alignment"
set autoindent		" maintain your current indentation level when going to a new line
set number			" show line numbers
set showcmd			" show command in bottom bar
set wildmenu		" visual autocomplete for command menu
set wildignore=*.o,*~,*.pyc " ignore compiled files
set ruler			" show ruler!"
set showmatch		" highlight matching braces and parens

" make searching better
set ignorecase
set smartcase
set incsearch		" moves cursor while searching

set lazyredraw 	" don't draw during macros

" Move between windows
map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

" Close the current buffer
imap jj <Esc>
nmap ; :
 
" move vertically by visual line
nnoremap j gj
nnoremap k gk

" shift a line up or down
nnoremap <C-S-j> :m .+1<CR>==
nnoremap <C-S-k> :m .-2<CR>==
inoremap <C-S-j> <Esc>:m .+1<CR>==gi
inoremap <C-S-k> <Esc>:m .-2<CR>==gi
vnoremap <C-S-j> :m '>+1<CR>gv=gv
vnoremap <C-S-k> :m '<-2<CR>gv=gv

"change leader to ,
let mapleader = ','
let g:mapleader = ','

filetype indent on	" load file-type specific indent files
filetype plugin on	" load file-type specific plugins

"Learning vimscript the hard way
nnoremap <leader>ev :vsplit $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>
nnoremap <C-S> :w<cr>
inoremap <C-S> <ESC>:w<cr>

"latex-suite
"set grepprg=grep\ -nH\ \'$*\'
"let g:tex_flavor='latex'
"let g:Tex_BibtexFlavor='biber'
"let g:Tex_DefaultTargetFormat='pdf'
"let g:Tex_FormatDependency_pdf='pdf'
"let g:Tex_ViewRule_pdf='zathura "$@" 2>/dev/null'
"let g:Tex_ViewRuleComplete_pdf='zathura'
"let g:Tex_CompileRule_pdf='xelatex --interaction=nonstopmode $*'

"vimtex
set iskeyword+=:
let g:tex_flavor='latex'
let g:vimtex_view_method='zathura'

" For when I forget sudo
cmap w!! w !sudo tee > /dev/null %

" Automatically check the file on write
autocmd! BufWritePost * Neomake

" reformat on tab
nnoremap <Ctrl-I> =$

