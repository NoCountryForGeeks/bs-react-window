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
      ~onItemsRendered: (SharedList.internalOnItemsRendered => unit)=?,
      ~onScroll: (SharedList.internalOnScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: SharedList.internalCellProps => React.element
    ) =>
    React.element = "VariableSizeList";
};

[@react.component]
let make =
    (
      ~className: string=?,
      ~direction: SharedList.direction,
      ~estimatedItemSize: int=?,
      ~height: int, /* int or string*/
      ~initialScrollOffset: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      ~itemCount: int,
      /*~itemData: any*/
      /*~itemKey: function*/
      ~itemSize:  int => int,
      ~layout: SharedList.layout,
      ~onItemsRendered: (SharedList.onItemsRendered => unit)=?,
      ~onScroll: (SharedList.onScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanCount: int=?,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: SharedList.cellProps => React.element
    ) => 

    /*Methods*/
    /*scrollTo(scrollOffset: number): void*/
    /*scrollToItem(index: number, align: string = "auto"): void*/
    /*resetAfterIndex(index: number, shouldForceUpdate: boolean = true): void*/

  <InternalVariableSizeList
    className
    direction={SharedList.parseDirection(direction)}
    estimatedItemSize
    height
    initialScrollOffset
    /*innerRef*/
    /*innerElementType*/
    itemCount
    /*itemData*/
    /*itemKey*/
    itemSize
    layout={SharedList.parseLayout(layout)}
    onItemsRendered={internalOnItemsRendered => onItemsRendered(SharedList.parseOnItemsRendered(internalOnItemsRendered))}
    onScroll={internalOnScroll => onScroll(SharedList.parseOnScroll(internalOnScroll))}
    /*outerRef*/
    /*outerElementType*/
    overscanCount
    style
    useIsScrolling
    width
  >
    {internalCellProps => children(SharedList.parseChildrenProps(internalCellProps))}
  </InternalVariableSizeList>;