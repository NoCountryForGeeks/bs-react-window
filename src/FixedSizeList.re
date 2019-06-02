type cellProps = {
  index: int,
  style: ReactDOMRe.style,
  /*isScrolling: undefined, true or false It depends on prop useIsScrolling of list*/
  /*data: any, it depends on itemData prop of list*/
}

type internalCellProps = Js.t({
  .
    index: int,
    style: ReactDOMRe.style
});

type direction = 
  | Ltr
  | Rtl;

let parseDirection = direction => switch (direction) {
  | Ltr => "ltr"
  | Rtl => "rtl"
  };

type layout = 
  | Horizontal
  | Vertical;

let parseLayout = layout => switch (layout) {
  | Vertical => "vertical"
  | Horizontal => "horizontal"
  };

type onItemsRendered = {
  overscanStartIndex: int,
  overscanStopIndex: int,
  visibleStartIndex: int,
  visibleStopIndex: int
}

let parseChildrenProps = (internalCellProps: internalCellProps) => {
  let cellProps: cellProps = {
    index: internalCellProps##index,
    style: internalCellProps##style
  }
  cellProps;
}

module InternalFixedSizeGrid = {
  [@bs.module "react-window"] [@react.component]
  external make:
    (
      ~className: string=?,
      ~direction: string,
      ~height: int, /* int or string*/
      ~initialScrollOffset: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      ~itemCount: int,
      /*~itemData: any*/
      /*~itemKey: function*/
      ~itemSize: int,
      ~layout: string,
      ~onItemsRendered: (onItemsRendered => unit)=?,
      /*~onScroll: function*/
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int,
      ~children: internalCellProps => React.element
    ) =>
    React.element = "FixedSizeList";
};

[@react.component]
let make =
    (
      ~className: string=?,
      ~direction: direction,
      ~height: int, /* int or string*/
      ~initialScrollOffset: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      ~itemCount: int,
      /*~itemData: any*/
      /*~itemKey: function*/
      ~itemSize: int,
      ~layout: layout,
      ~onItemsRendered: (onItemsRendered => unit)=?,
      /*~onScroll: function*/
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int,
      ~children: cellProps => React.element
    ) => 

    /*Methods*/
    /*scrollTo(scrollOffset: number): void*/
    /*scrollToItem(index: number, align: string = "auto"): void*/

  <InternalFixedSizeGrid
    className
    direction={parseDirection(direction)}
    height
    initialScrollOffset
    /*innerRef*/
    /*innerElementType*/
    itemCount
    /*itemData*/
    /*itemKey*/
    itemSize
    layout={parseLayout(layout)}
    onItemsRendered
    /*onScroll*/
    /*outerRef*/
    /*outerElementType*/
    overscanCount
    style
    useIsScrolling
    width
  >
    {internalCellProps => children(parseChildrenProps(internalCellProps))}
  </InternalFixedSizeGrid>;