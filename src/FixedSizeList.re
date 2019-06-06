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

type internalOnItemsRendered = Js.t({
  .
  overscanStartIndex: int,
  overscanStopIndex: int,
  visibleStartIndex: int,
  visibleStopIndex: int
})

type onItemsRendered = {
  overscanStartIndex: int,
  overscanStopIndex: int,
  visibleStartIndex: int,
  visibleStopIndex: int
}

let parseOnItemsRendered = (internalOnItemsRendered: internalOnItemsRendered) => {
  let onItemsRendered = {
    overscanStartIndex: internalOnItemsRendered##overscanStartIndex,
    overscanStopIndex: internalOnItemsRendered##overscanStopIndex,
    visibleStartIndex: internalOnItemsRendered##visibleStartIndex,
    visibleStopIndex: internalOnItemsRendered##visibleStopIndex
  }
  onItemsRendered;
}

type scrollDirection = 
  | Backward
  | Forward

type internalOnScroll = Js.t({
  .
  scrollDirection: string,
  scrollOffset: int,
  scrollUpdateWasRequested: bool
})

type onScroll = {
  scrollDirection: scrollDirection,
  scrollOffset: int,
  scrollUpdateWasRequested: bool
}

let parseOnScroll = (internalOnScroll: internalOnScroll) => {
  let scrollDirection = switch (internalOnScroll##scrollDirection) {
    | "backward" => Backward
    | "forward" => Forward
  };

  let onScroll: onScroll = {
    scrollDirection: scrollDirection,
    scrollOffset: internalOnScroll##scrollOffset,
    scrollUpdateWasRequested: internalOnScroll##scrollUpdateWasRequested
  }
  onScroll;
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
      ~onItemsRendered: (internalOnItemsRendered => unit)=?,
      ~onScroll: (internalOnScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
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
      ~onScroll: (onScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
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
    onItemsRendered={internalOnItemsRendered => onItemsRendered(parseOnItemsRendered(internalOnItemsRendered))}
    onScroll={internalOnScroll => onScroll(parseOnScroll(internalOnScroll))}
    /*outerRef*/
    /*outerElementType*/
    overscanCount
    style
    useIsScrolling
    width
  >
    {internalCellProps => children(parseChildrenProps(internalCellProps))}
  </InternalFixedSizeGrid>;