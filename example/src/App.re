open ReasonWindow;

[@react.component]
let make = () => {
    <FixedSizeList
        height={200}
        itemCount={1000}
        itemSize={50}
        width={200}
    >
        {rowProps => <Row rowProps/>}
    </FixedSizeList>
};