module InternalVariableSizeList = {
  [@bs.module "react-window"] [@react.component]
  external make:
    (
      ~className: string=?,
      ~direction: string,
      ~estimatedItemSize: int=?,
      ~height: int, /* int or string*/
      ~initialScrollOffset: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      ~itemCount: int,
      /*~itemData: any*/
      /*~itemKey: function*/
      ~itemSize: int => int,
      ~layout: string,
      ~onItemsRendered: (List.internalOnItemsRendered => unit)=?,
      ~onScroll: (List.internalOnScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: List.internalCellProps => React.element
    ) =>
    React.element = "VariableSizeList";
};

[@react.component]
let make =
    (
      ~className: string=?,
      ~direction: List.direction,
      ~estimatedItemSize: int=?,
      ~height: int, /* int or string*/
      ~initialScrollOffset: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      ~itemCount: int,
      /*~itemData: any*/
      /*~itemKey: function*/
      ~itemSize:  int => int,
      ~layout: List.layout,
      ~onItemsRendered: (List.onItemsRendered => unit)=?,
      ~onScroll: (List.onScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: List.cellProps => React.element
    ) => 

    /*Methods*/
    /*scrollTo(scrollOffset: number): void*/
    /*scrollToItem(index: number, align: string = "auto"): void*/
    /*resetAfterIndex(index: number, shouldForceUpdate: boolean = true): void*/

  <InternalVariableSizeList
    className
    direction={List.parseDirection(direction)}
    estimatedItemSize
    height
    initialScrollOffset
    /*innerRef*/
    /*innerElementType*/
    itemCount
    /*itemData*/
    /*itemKey*/
    itemSize
    layout={List.parseLayout(layout)}
    onItemsRendered={internalOnItemsRendered => onItemsRendered(List.parseOnItemsRendered(internalOnItemsRendered))}
    onScroll={internalOnScroll => onScroll(List.parseOnScroll(internalOnScroll))}
    /*outerRef*/
    /*outerElementType*/
    overscanCount
    style
    useIsScrolling
    width
  >
    {internalCellProps => children(List.parseChildrenProps(internalCellProps))}
  </InternalVariableSizeList>;