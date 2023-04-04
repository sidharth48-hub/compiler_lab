 val = initialize();
    Root = null;
 
 while(val!=0) do
      breakpoint;
      Root = insert(Root,val);
      read(val);
    endwhile;

    in = inOrder(Root);