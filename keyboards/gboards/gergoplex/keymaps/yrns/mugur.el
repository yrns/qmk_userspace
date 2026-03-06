(let ((mugur-qmk-path "~/src/clone/qmk_userspace")
      (mugur-keyboard-name "gboards/gergoplex")
      (mugur-layout-name "LAYOUT_split_3x5_3")
      (mugur-keymap-name "yrns")
      (mugur-tapping-term 175)
      (mugur-user-defined-keys '((email "hello@yrns.org")
                                 (replay (C-x e)))))

 (mugur-mugur
  '(("base"
     q   w   f   p   g          j   l   u   y  ?\;
     a   r   s   t   d          h   n   e   i   o
     z   x   c   v   b          k   m  ?\, dot ?\/
     (LT fn esc) (LT num space) (LT sym tab)   (ralt ent) (rshift bspace) (rctrl del))

    ("mods"
     --- --- --- --- ---  --- --- --- --- ---
     --- --- --- --- ---  --- --- --- --- ---
     --- --- --- --- ---  --- --- --- --- ---
     --- --- ---
     )

    ("num"
     ~  ?\!  ?\@  ?\# ?\$ ?\%     ?\^  ?\&  ?\*   -   =  bspace
     0   1    2    3   4    5      6    7    8    9   0  (LT move ent)
     S  --- ?\< ?\{  ?\[  ?\(     ?\)  ?\]  ?\}  ?\>  |  (MO emacs)
     (TG qmik) C-M ---   --- S (TG numeric))

    ("move"
     --- M-v   up   ---  --- ---    --- --- --- --- --- ---
     C-a left down right C-e ---    --- --- --- --- --- ---
     --- M-<  C-v   M->  --- ---    --- --- --- --- --- ---
     --- --- ---  ---  --- --- )

    ("emacs"
     esc  --- --- (C-x 0) (C-x 2) (C-x 3)   (C-x 4 t)  --- --- --- --- ---
     ---  --- M-% --- --- (M-x "gtd" ent)   (C-x b)    --- --- "λ" --- ---
     reset --- M-x C-c ---  ?\(               ?\)  (M-x "magit" ent) --- --- --- ---
     --- ---  (H-i e)             (C-x 8) --- (MO hypm))

    ("hypm"
     --- --- --- --- --- ---    --- --- H-i  (H-i o) (H-i l) ---
     --- --- --- H-d --- ---    --- --- ---  --- --- ---
     --- --- --- --- --- ---    --- H-m (H-m s) --- --- ---
     --- --- ---  ---  --- --- )

    ("qmik"
     ---    rgb_tog rgb_mod --- --- ---    --- --- --- --- --- reset
     rgb_sad rgb_vad rgb_hud --- --- ---    --- --- --- --- --- ---
     rgb_sai rgb_vai rgb_hui --- --- ---    --- --- --- ---  S  ---
     --- --- ---  ---  --- --- )
    )))
