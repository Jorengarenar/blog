autocmd FileType c,cpp syn match cUserLabel2 /\v%(goto\s+)@<=\k+\ze;/
autocmd FileType c,cpp syn match cFunction /\v\k+\ze\(.*\)/ containedin=cBlock

hi link cUserLabel2 cUserLabel
hi cUserLabel ctermfg=yellow
hi cFunction ctermfg=cyan
