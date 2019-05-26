[@bs.module "react-window"]
external reactClass : ReasonReact.reactClass = "FixedSizeList";

[@bs.obj]
external makeProps:
  (
    ~height: int,
    ~itemCount: int,
    ~itemSize: int,
    ~width: int,
    unit
  ) =>
  _ =
  "";

let make = ( 
  ~height, 
  ~itemCount, 
  ~itemSize, 
  ~width, 
  children
) => 
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props= makeProps(
      ~height,
      ~itemCount,
      ~itemSize,
      ~width,
      ()
    ),
    children
  );