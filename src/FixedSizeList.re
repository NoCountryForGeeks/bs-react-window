type rowProps = {
  index: int,
  style: ReactDOMRe.style
}

type internalRowProps = Js.t({
  .
    index: int,
    style: ReactDOMRe.style
});

let createChildrenProps = (internalRowProps: internalRowProps) => {
  let rowProps: rowProps = {
    index: internalRowProps##index,
    style: internalRowProps##style
  }
  rowProps;
}

module InternalFixedSizeGrid = {
  [@bs.module "react-window"] [@react.component]
  external make:
    (
      ~height: int,
      ~itemCount: int,
      ~itemSize: int,
      ~width: int,
      ~children: internalRowProps => React.element
    ) =>
    React.element = "FixedSizeList";
};

[@react.component]
let make =
    (
      ~height: int,
      ~itemCount: int,
      ~itemSize: int,
      ~width: int,
      ~children: rowProps => React.element
    ) => 
  <InternalFixedSizeGrid
    height
    itemCount
    itemSize
    width
  >
    {internalRowProps => children(createChildrenProps(internalRowProps))}
  </InternalFixedSizeGrid>;