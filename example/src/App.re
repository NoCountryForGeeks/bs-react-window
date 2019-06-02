open ReasonWindow;

[@react.component]
let make = () => {
    <FixedSizeList
        className={"prueba"}
        direction={FixedSizeList.Rtl}
        height={200}
        itemCount={1000}
        itemSize={50}
        layout={FixedSizeList.Horizontal}
        onItemsRendered={onItemsRendered => Js.log(onItemsRendered)}
        useIsScrolling={true}
        style={ReactDOMRe.Style.make(~background="red", ())}
        overscanCount={10}
        width={200}
    >
        {cellProps => <Cell cellProps/>}
    </FixedSizeList>
};